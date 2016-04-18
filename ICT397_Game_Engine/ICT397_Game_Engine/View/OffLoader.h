#ifndef OFFLOADER_H
#define OFFLOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <GL/freeglut.h>

using namespace std;

class OffLoader
{
public:

	string Load(string t_modelPath, int t_index);

	void Draw(const int t_index);

	void SetModelNum(int t_size);

private:

	ifstream m_modelFile;
	stringstream m_string;

	typedef struct Vector3{double x, y, z;} Vector3;

	typedef struct FaceVec{
		int faceType;
		Vector3 coord1, coord2, coord3;
	} FaceVec;

	typedef struct Objects{
		Vector3 *coords;
		FaceVec *facets;
		int vLines, fLines, uLines;
	} Objects;

	Objects *m_objectList;

};

#endif // OBJLOADER_H
