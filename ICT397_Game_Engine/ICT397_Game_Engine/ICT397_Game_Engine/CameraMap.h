#ifndef CAMERA_MAP_H
#define CAMERA_MAP_H

#include <gl/glut.h>

//--------------------------------------------------------------------------------------

class CameraMap
{
public:
	CameraMap() {};
	virtual ~CameraMap() {};

	//----------------------------------------------------------------------------------

	// display the map
	void DisplayMap(const int & screenWidth, const int & screenHeight,
				    const GLdouble & xPos, const GLdouble & zPos,
					const GLuint & tempImage);

	// display the welcome screen
	void DisplayWelcomeScreen (const int & screenWidth, const int & screenHeight, 
		                       const int & tempExit, const GLuint & tempImage);

	void DisplayNoExit (const int & screenWidth, const int & screenHeight, 
						const GLuint & tempImage);

private:
    // Privatised copy constructor and assignment operator
    CameraMap (const CameraMap &cam) {};
    CameraMap &operator = (const CameraMap &cam) {};
};

#endif

//--------------------------------------------------------------------------------------