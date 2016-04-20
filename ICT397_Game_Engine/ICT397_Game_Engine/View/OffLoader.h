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
	/**
        * @brief Load models
        *
        * Loads models from .off files
        *
		* @param string t_modelPath - Model Path
		* @param int t_index - array index
        * @return string - debug
        */
	string Load(string t_modelPath, int t_index);

	/**
        * @brief Draws models
        *
        * Draws loaded models
        *
		* @param const int t_index - Array index
        * @return void
        */
	void Draw(const int t_index);

	/**
        * @brief Sets max models
        *
        * Sets max size of model array
        *
		* @param int t_size - Array size
        * @return void
        */
	void SetModelNum(int t_size);

private:

	/** 
	 *	Class Member
	 *	This variable is an ifstream instance
	 */
	ifstream m_modelFile;

	/** 
	 *	Class Member
	 *	This variable is an stringstream instance
	 */
	stringstream m_string;

	/** 
	 *	Class Member
	 *	This variable is a Vector3 Struct definition
	 */
	typedef struct Vector3{double x, y, z;} Vector3;

	/** 
	 *	Class Member
	 *	This variable is a FaceVec Struct definition
	 */
	typedef struct FaceVec{
		int faceType;
		Vector3 coord1, coord2, coord3;
	} FaceVec;

	/** 
	 *	Class Member
	 *	This variable is an Objects Struct definition
	 */
	typedef struct Objects{
		Vector3 *coords;
		FaceVec *facets;
		int vLines, fLines, uLines;
	} Objects;

	/** 
	 *	Class Member
	 *	This variable is an Objects instance
	 */
	Objects *m_objectList;

};

#endif // OBJLOADER_H
