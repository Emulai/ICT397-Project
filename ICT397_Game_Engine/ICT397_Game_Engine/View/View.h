#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <GL/glut.h>
#include <cassert>
#include "OffLoader.h"
#include "..\Libraries\bullet3-2.83.7\bullet3-2.83.7\examples\ThirdPartyLibs\Wavefront\tiny_obj_loader.h"

class View
{
public:

	/**
        * @brief Default constructor of class View
        *
        * This constructor sets the variables of class View to the default
        * values
        *
        */
	View();

	/**
        * @brief Loads models from file
        *
        * This function calls loaders' load functions
        *
        * @param string t_modelPath - Model Path
		* @param const int t_index - Array index
        * @return void
        */
	void LoadModel(string t_modelPath, const int t_index);

	/**
        * @brief Renders models
        *
        * This function renders loaded models
        *
        * @return void
        */
	void Render();

	/**
        * @brief Sets max num of Objects in array
        *
        * This function sets max array size
        *
		* @param int t_size - Array size
        * @return void
        */
	void SetModelNum(int t_size);

	void GameView(float t_x, float t_z, float t_lx, float t_lz);

	//////////////////////////
	//Function to DISPLAY menus here
	//Menu INTERACTION in Controller
	//////////////////////////
	void SetLocalWindowSize(float t_newWindowWidth, float t_newWindowHeight);

	void EnterMenuState();

	void EnterGameState();

	void MenuView();

	/****************************************
	 * returns a short indicating what button was pressed.
	 * Numbers start with 1 at the bottom button to 5 at the top button
	 * -1 is a sentinel for no interaction
	 * takes arguments originating from OpenGL API indicating location of a mouse click on screen
	 *
	 * Currently: 1= EXIT, 5=Return (to game state)
	****************************************/
	short CheckForButton(int t_x, int t_y);

	float GetWindowWidth();
	float GetWindowHeight();

private:

	float m_windowWidth, m_windowHeight;

	/** 
	 *	Class Member
	 *	This variable is an instance of OffLoader
	 */
	OffLoader m_off;

	/** 
	 *	Class Member
	 *	This variable holds debug strings from loaders
	 */
	string m_debug;

};

#endif