#include "ObjLoader.h"

ObjectLoader::ObjectLoader()
{
	P = mat4(1);
	MV = mat4(1);

	lightPosOS = vec3(0,2,0);

	theta = 0.66f;
	phi = -1.0f;
	radius = 70;

	mesh_filename = "../media/blocks.obj";
}

void ObjectLoader::OnInit()
{
	string mesh_path = mesh_filename.substr(0, mesh_filename.find_last_of("/")+1);

	if(!obj.Load(mesh_filename.c_str(), meshes, vertices, indices, materials))
	{
		cout << "Cannot load the 3ds mesh" << endl;
		exit(EXIT_FAILURE);
	}
	GL_CHECK_ERRORS

	for(size_t k = 0; k < materials.size(); k++)
	{
		if(materials[k]->map_Kd != "")
		{
			GLuint id = 0;
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_2D, id);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			int texture_width = 0, texture_height = 0, channels = 0;

			const string& filename = materials[k]->map_Kd;

			string full_filename = mesh_path;
			full_filename.append(filename);

			GLubyte* pData = SOIL_load_image(full_filename.c_str(), &texture_width, &texture_height, &channels, SOIL_LOAD_AUTO);
			if(pData == NULL)
			{
				cerr << "Cannot load image: " << full_filename.c_str() << endl;
				exit(EXIT_FAILURE);
			}

			int i, j;
			for(j = 0; j*2 < texture_height; ++j)
			{
				int index1 = j * texture_width * channels;
				int index2 = (texture_height - 1 - j) * texture_width * channels;
				for(i = texture_width * channels; i > 0; --i)
				{
					GLubyte temp = pData[index1];
					pData[index1] = pData[index2];
					pData[index2] = temp;
					++index1;
					++index2;
				}
			}

			GLenum format = GL_RGBA;
			switch(channels)
			{
			case 2: format = GL_RG32UI; break;
			case 3: format = GL_RGB;	break;
			case 4: format = GL_RGBA;	break;
			}

			glTexImage2D(GL_TEXTURE_2D, 0, format, texture_width, texture_height,0, format, GL_UNSIGNED_BYTE, pData);

			SOIL_free_image_data(pData);

			textures.push_back(id);
		}
	}
	GL_CHECK_ERRORS

	flatShader.LoadFromFile(GL_VERTEX_SHADER, "shaders/flat.vert");
	flatShader.LoadFromFile(GL_FRAGMENT_SHADER, "shaders/flat.frag");

	shader.CreateAndLinkProgram();
	shader.Use();

	shader.AddAttribute("vVertex");
	shader.AddAttribute("vNormal");
	shader.AddAttribute("vUV");
	shader.AddUniform("MV");
	shader.AddUniform("N");
	shader.AddUniform("P");
	shader.AddUniform("textureMap");
	shader.AddUniform("useDefault");
	shader.AddUniform("light_position");
	shader.AddUniform("diffuse_color");

	glUniform1i(shader("textureMap"), 0);
	shader.UnUse();

	GL_CHECK_ERRORS

	glGenVertexArrays(1, &vaoID);
	glGenBuffers(1, &vboVerticesID);
	glGenBuffers(1, &vboIndicesID);

	glBindVertexArray(vaoID);
	glBindBuffer(GL_ARRAY_BUFFER, vboVerticesID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertices.size(), &(vertices[0].pos.x), GL_STATIC_DRAW);
	GL_CHECK_ERRORS

	glEnableVertexAttribArray(shader["vVertex"]);
	glVertexAttribPointer(shader["vVertex"], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	GL_CHECK_ERRORS

	glEnableVertexAttribArray(shader["vNormal"]);
	glVertexAttribPointer(shader["vNormal"], 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, normal)));
	GL_CHECK_ERRORS

	glEnableVertexAttribArray(shader["vUV"]);
	glVertexAttribPointer(shader["vUV"], 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(offsetof(Vertex, uv)));
	GL_CHECK_ERRORS

	if(materials.size()==1)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)*indices.size(), &(indices[0]), GL_STATIC_DRAW);
	}
	GL_CHECK_ERRORS
	glBindVertexArray(0);

	vec3 crossHairVertices[6];
	crossHairVertices[0] = vec3(-0.5f, 0, 0);
	crossHairVertices[1] = vec3(0.5f, 0, 0);
	crossHairVertices[2] = vec3(0, -0.5f, 0);
	crossHairVertices[3] = vec3(0, 0.5f, 0);
	crossHairVertices[4] = vec3(0, 0, -0.5f);
	crossHairVertices[5] = vec3(0, 0, 0.5f);

	glGenVertexArrays(1, &lightVAOID);
	glGenBuffers(1, &lightVerticesVBO);
	glBindVertexArray(lightVAOID);

	glBindBuffer(GL_ARRAY_BUFFER, lightVerticesVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(crossHairVertices), &(crossHairVertices[0].x), GL_STATIC_DRAW);
	GL_CHECK_ERRORS

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	GL_CHECK_ERRORS

	lightPosOS.x = radius * cos(theta)*sin(phi);
	lightPosOS.y = radius * cos(phi);
	lightPosOS.z = radius * sin(theta)*sin(phi);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glClearColor(0.5, 0.5, 1, 1);
	cout << "Initialisation successful" << endl;
}

void ObjectLoader::OnShutdown()
{
	size_t total_textures = textures.size();
	for(size_t i = 0; i < total_textures; i++)
	{
		glDeleteTextures(1, &textures[i]);
	}
	textures.clear();

	size_t total_meshes = meshes.size();
	for(size_t i = 0; i < total_meshes; i++)
	{
		delete meshes[i];
		materials[i] = 0;
	}
	meshes.clear();

	size_t total_materials = materials.size();
	for(size_t i = 0; i < total_materials; i++)
	{
		delete materials[i];
		materials[i] = 0;
	}
	materials.clear();

	shader.DeleteShaderProgram();
	flatShader.DeleteShaderProgram();

	glDeleteBuffers(1, &vboVerticesID);
	glDeleteBuffers(1, &vboIndicesID);
	glDeleteVertexArrays(1, &vaoID);

	glDeleteVertexArrays(1, &lightVAOID);
	glDeleteBuffers(1, &lightVerticesVBO);

	cout << "Shutdown successful" << endl;
}

void ObjectLoader::OnResize(int w, int h)
{
	P = perspective(60.0f,(float)w/h, 0.1f, 1000.0f);
}

void ObjectLoader::OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//SKIPPED CODE
	glBindVertexArray(vaoID);
	{

		shader.Use();

		glUniformMatrix4fv(shader("MV"), 1, GL_FALSE, value_ptr(MV));
		glUniformMatrix3fv(shader("N"), 1, GL_FALSE, value_ptr(inverseTranspose(mat3(MV))));
		glUniformMatrix4fv(shader("P"), 1, GL_FALSE, value_ptr(P));
		glUniform3fv(shader("light_position"), 1, &(lightPosOS.x));

		for(size_t i = 0; i < materials.size(); i++)
		{
			Material* pMat = materials[i];
			if(pMat->map_Kd != "")
			{
				glUniform1f(shader("useDefault"), 0.0);
				GLint whichID[1];
				glGetIntegerv(GL_TEXTURE_BINDING_2D, whichID);
				if(whichID[0] != textures[i])
					glBindTexture(GL_TEXTURE_2D, textures[i]);
			}
			else
				glUniform1f(shader("useDefault"), 1.0);

			if(materials.size() == 1)
				glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, 0);
			else
				glDrawElements(GL_TRIANGLES, pMat->count, GL_UNSIGNED_SHORT, (const GLvoid*)(&indices[pMat->offset]));
		}

		shader.UnUse();

	}

	glDisable(GL_DEPTH_TEST);

	glBindVertexArray(lightVAOID);
	{
		mat4 T = translate(mat4(1), lightPosOS);
		
		flatShader.Use();

		glUniformMatrix4fv(flatShader("MVP"), 1, GL_FALSE, value_ptr(P*MV*T));
		glDrawArrays(GL_LINES, 0, 6);

		flatShader.UnUse();
	}

	glEnable(GL_DEPTH_TEST);

	glutSwapBuffers();
}