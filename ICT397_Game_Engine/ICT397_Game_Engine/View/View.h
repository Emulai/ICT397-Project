#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "OffLoader.h"

using namespace std;

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

	//////////////////////////
	//Function to DISPLAY menus here
	//Menu INTERACTION in Controller
	//////////////////////////

private:

	OffLoader m_off;

	string m_debug;

};

#endif