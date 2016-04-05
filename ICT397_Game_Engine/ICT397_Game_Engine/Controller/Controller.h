#ifndef CONTROLLER_H
#define CONTROLLER_H

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

private:

	Model m_model;
	View m_view;

};

#endif