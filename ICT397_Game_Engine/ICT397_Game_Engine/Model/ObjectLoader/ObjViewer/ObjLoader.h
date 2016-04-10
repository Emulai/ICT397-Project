#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_inverse.hpp>

#include "../src/GLSLShader.h"
#include <vector>
#include "Obj.h"

#include <SOIL.h>

#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "SOIL.lib")

using namespace std;
using namespace glm;

class ObjectLoader
{
public:

	ObjectLoader();

	void OnInit();

	void OnShutdown();

	void OnResize(int w, int h);

	void OnRender();

private:

	GLSLShader shader, flatShader;

	GLuint vaoID;
	GLuint vboVerticesID;
	GLuint vboIndicesID;

	mat4  P;
	mat4 MV;



	ObjLoader obj;
	vector<Mesh*> meshes;
	vector<Material*> materials;
	vector<unsigned short> indices;
	vector<Vertex> vertices;
	vector<GLuint> textures;

	GLuint lightVAOID;
	GLuint lightVerticesVBO;

	vec3 lightPosOS;

	float theta;
	float phi;
	float radius;

	string mesh_filename;

};

#endif