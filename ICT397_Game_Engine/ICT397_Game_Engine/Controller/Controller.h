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

	void MenuPress(int x, int y){
		m_view.CheckForButton(x, y);
	}

	void MenuInit(float windowWidth, float windowHeight){
		m_view.SetLocalWindowSize(windowWidth, windowHeight);
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

		double ratio =  GetWindowWidth() * 1.0 / GetWindowHeight();

		gluPerspective(45.0f, ratio, 0.1f, 100.0f);
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