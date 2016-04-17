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
	void ModelTest();

	/////////////////////
	//INTERACTION with menu here
	//Menu DISPLAY is in View
	/////////////////////
	void MenuCtrl(){
		m_view.MenuView();
	}

	void MenuPress(int t_x, int t_y){
		short l_actionType;
		extern short g_gameState;

		l_actionType = m_view.CheckForButton(t_x, t_y);

		switch(l_actionType){
			//terminate program
			case 1: exit(0);
				break;
			//Exit menu to game state
			case 5: g_gameState = 0;
				EnterGameState();
				break;
		}
	}

	void MenuInit(float t_windowWidth, float t_windowHeight){
		m_view.SetLocalWindowSize(t_windowWidth, t_windowHeight);
	}

	float GetWindowWidth(){
		return(m_view.GetWindowWidth());
	}
	float GetWindowHeight(){
		return(m_view.GetWindowHeight());
	}

	void EnterMenuState(){
		m_view.EnterMenuState();
	}

	void EnterGameState(){
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();

		double l_ratio =  GetWindowWidth() * 1.0 / GetWindowHeight();

		gluPerspective(45.0f, l_ratio, 0.1f, 100.0f);
		cout << "Switching to game state" <<endl;
		glEnable(GLUT_DEPTH);

		glMatrixMode(GL_MODELVIEW);
		glutPostRedisplay();
	}

private:

	Model m_model;
	View m_view;

};

#endif