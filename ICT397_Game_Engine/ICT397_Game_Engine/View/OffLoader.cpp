#include "OffLoader.h"

string OffLoader::Load(string t_modelPath, int t_index)
{

	m_modelFile.open(t_modelPath);

    string str;

        if(!m_modelFile.is_open())
        {
            return ("File not opened\n");
        }else
        {
            m_modelFile >> str;

                if(str == "OFF")
                {
                    // Get Vertex Lines and Face Lines
                    m_modelFile >> m_objectList[t_index].vLines;
                    m_modelFile >> m_objectList[t_index].fLines;
                    m_modelFile >> m_objectList[t_index].uLines;

                }else
                {
                    return ("File not OFF\n");
                }
            
        }

        m_objectList[t_index].coords = new Vector3 [m_objectList[t_index].vLines];
        m_objectList[t_index].facets = new FaceVec [m_objectList[t_index].fLines];

        for(int i = 0; i < m_objectList[t_index].vLines; i++)
        {

			m_modelFile >> m_objectList[t_index].coords[i].x;
			m_modelFile >> m_objectList[t_index].coords[i].y;
			m_modelFile >> m_objectList[t_index].coords[i].z;

        }

        int l_vertLine1, l_vertLine2, l_vertLine3;

        for(int i = 0; i < m_objectList[t_index].fLines; i++)
        {
            m_modelFile >> m_objectList[t_index].facets[i].faceType;

            if ((m_objectList[t_index].facets)[i].faceType == 3)
            {
                m_modelFile >> l_vertLine1;
                (m_objectList[t_index].facets)[i].coord1.x = (m_objectList[t_index].coords)[l_vertLine1].x;
                (m_objectList[t_index].facets)[i].coord1.y = (m_objectList[t_index].coords)[l_vertLine1].y;
                (m_objectList[t_index].facets)[i].coord1.z = (m_objectList[t_index].coords)[l_vertLine1].z;

                m_modelFile >> l_vertLine2;
                (m_objectList[t_index].facets)[i].coord2.x = (m_objectList[t_index].coords)[l_vertLine2].x;
                (m_objectList[t_index].facets)[i].coord2.y = (m_objectList[t_index].coords)[l_vertLine2].y;
                (m_objectList[t_index].facets)[i].coord2.z = (m_objectList[t_index].coords)[l_vertLine2].z;

                m_modelFile >> l_vertLine3;
                (m_objectList[t_index].facets)[i].coord3.x = (m_objectList[t_index].coords)[l_vertLine3].x;
                (m_objectList[t_index].facets)[i].coord3.y = (m_objectList[t_index].coords)[l_vertLine3].y;
                (m_objectList[t_index].facets)[i].coord3.z = (m_objectList[t_index].coords)[l_vertLine3].z;

            }

        }

        return ("Model loaded\n");
}

void OffLoader::Draw(const int t_index)
{
    //Generate model
    for(int i = 0; i < m_objectList[t_index].fLines; i++)
    {
        switch((m_objectList[t_index].facets)[i].faceType)
        {
        case 3://Triangles
            glBegin(GL_TRIANGLES);
            glVertex3f((m_objectList[t_index].facets)[i].coord1.x, (m_objectList[t_index].facets)[i].coord1.y, (m_objectList[t_index].facets)[i].coord1.z);
			cout << "Vert 1 >> " << m_objectList[t_index].facets[i].coord1.x << ", " << m_objectList[t_index].facets[i].coord1.y << ", " << m_objectList[t_index].facets[i].coord1.z << " <<" << endl;
            glVertex3f((m_objectList[t_index].facets)[i].coord2.x, (m_objectList[t_index].facets)[i].coord2.y, (m_objectList[t_index].facets)[i].coord2.z);
			cout << "Vert 2 >> " << m_objectList[t_index].facets[i].coord2.x << ", " << m_objectList[t_index].facets[i].coord2.y << ", " << m_objectList[t_index].facets[i].coord2.z << " <<" << endl;
            glVertex3f((m_objectList[t_index].facets)[i].coord3.x, (m_objectList[t_index].facets)[i].coord3.y, (m_objectList[t_index].facets)[i].coord3.z);
			cout << "Vert 3 >> " << m_objectList[t_index].facets[i].coord3.x << ", " << m_objectList[t_index].facets[i].coord3.y << ", " << m_objectList[t_index].facets[i].coord3.z << " <<" << endl;
            glEnd();
            break;

        case 4://Quads
            break;
        }
		
    }
	//string j;
	//getline(cin, j);
}

void OffLoader::SetModelNum(int t_size)
{
	m_objectList = new Objects[t_size];
}
