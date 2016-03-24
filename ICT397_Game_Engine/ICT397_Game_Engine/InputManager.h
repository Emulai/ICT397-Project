/// InputManager - InputManager class definition
///----------------------------------------------------------------------------
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

///----------------------------------------------------------------------------

#include <iostream>
#include <GL/glut.h>


using namespace std;

///----------------------------------------------------------------------------
/// Using indentation so that comments don't clutter code

	/**
	* @class InputManager
	*
	* @author Adrian Hampel
	* @version 01
	* @date 24/03/2016, Started
	*
	* @todo Keep adding to the development.
	*/

///----------------------------------------------------------------------------

class InputManager
{
public:
	InputManager();

	InputManager(float angle, float lx, float lz, float x, float z, float y, float deltaAngle, float deltaMove, int xOrigin);
	/**
	* @brief	Default Constructor
	*
	* Initializes
	*
	**/

	void computePos(float deltaMove);

	void ProcessSpecialKeys(int key, int x, int y);
	/**
	* @brief	Default Constructor
	*
	* Initializes
	*
	**/

	 void processNormalKeys(unsigned char key, int x, int y);
	/**
	* @brief	Default Constructor
	*
	* Initializes
	*
	**/

	void mouseMove(int x, int y);
	/**
	* @brief	Default Constructor
	*
	* Initializes
	*
	**/

	void mouseButton(int button, int state, int x, int y);
	/**
	* @brief	Default Constructor
	*
	* Initializes
	*
	**/

private:
	Camera cam

};

#endif