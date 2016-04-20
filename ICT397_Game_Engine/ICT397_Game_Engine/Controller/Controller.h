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
        * @brief Loads models called in main
        *
        * This function loads models specified in main.
        *
		* @param string t_modelPath - Model path
		* @param int t_index - Array index
        * @return void
        */
	void ModelLoad(string t_modelPath, int t_index);

	/**
        * @brief Returns Model
        *
        * Returns a pointer to this instance of Model
        *
        * @return Model* - Pointer to Model instance
        */
	Model* GetModel();

	/**
        * @brief Returns View
        *
        * Returns a pointer to this instance of View
        *
        * @return View* - Pointer to View instance
        */
	View* GetView();

	/**
        * @brief Passer to View
        *
        * Should make use of GetView in calling function,
		* passes parameters to GameView in View
        *
		* @param float t_x
		* @param float t_z
		* @param float t_lx
		* @param float t_lz
        * @return void
        */
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

	/** 
	 *	Class Member
	 *	This variable is an instance of Model
	 */
	Model m_model;

	/** 
	 *	Class Member
	 *	This variable is an instance of View
	 */
	View m_view;

	/** 
	 *	Class Member
	 *	This variable ensures model files are read only once
	 */
	bool m_modelIsLoaded;
};

#endif