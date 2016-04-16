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
	void MenuCtrl(int windowHeight, int windowWidth){
		m_view.MenuView(windowHeight, windowWidth);
	}

private:

	Model m_model;
	View m_view;

};

#endif