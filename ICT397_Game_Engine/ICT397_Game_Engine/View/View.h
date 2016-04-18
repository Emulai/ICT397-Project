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

	void LoadModel(string t_modelPath, const int t_index);

	/**
        * @brief Renders models from the model list
        *
        * This function sets the Vector3 for transform of the GameObject to that supplied
        * by the client program
        *
        * @param int t_modelReference - Model Reference number
        * @return void
        */
	void Render();

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

	OffLoader m_off;

	string m_debug;

	//objloader obj;

	bool loaded;

	//int cube;

};

#endif