#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string.h>
#include "..\View\View.h"
#include "..\Model\Model.h"

using namespace std;

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

	/////////////////////
	//INTERACTION with menu here
	//Menu DISPLAY is in View
	/////////////////////

private:

	Model m_model;
	View m_view;

	bool m_modelsLoaded;

};

#endif