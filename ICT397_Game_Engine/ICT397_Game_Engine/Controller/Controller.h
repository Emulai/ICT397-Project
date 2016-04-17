#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<iostream>

#include "..\View\View.h"
#include "..\Model\Model.h"

class Controller
{
public:

	/**
        * @brief Default constructor of class Controller
        *
        * This constructor passes to Model class a reference to the View class instantiated
        * in Controller
        *
        */
	Controller();

	/**
        * @brief Runs the model test
        *
        * This function calls a function in Model called ObjectTypeTest.
        *
        * @return void
        */
	void ModelTest(string mPath, int iNdex);

	void GameCtrl(float t_x, float t_z, float t_lx, float t_lz);

	/////////////////////
	//INTERACTION with menu here
	//Menu DISPLAY is in View
	/////////////////////
	void MenuCtrl();

	void Credits();

	void Options();

	void ListCheckpoints();

	void MenuPress(int t_x, int t_y);

	void MenuInit(float t_windowWidth, float t_windowHeight);

	float GetWindowWidth();
	float GetWindowHeight();

	void EnterMenuState();

	void EnterGameState();

private:

	Model m_model;
	View m_view;

	bool m_modelIsLoaded;
};

#endif