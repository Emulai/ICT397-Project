#ifndef MODEL_H
#define MODEL_H

#include <cstdio>
#include <iostream>
#include "Lua\lua.hpp"
#include "GameAssetFactory.h"
#include "..\View\View.h"
#include "Memento.h"
#pragma comment(lib, "lua5.1.lib")
#pragma comment(lib, "luabindd.lib")
using namespace std;

#include <cstdio>



class Model
{
public:

	/**
        * @brief Default constructor of class Model
        *
        * This constructor sets the variables of class Model to the default
        * values
        *
        */
	Model();

	/**
        * @brief Destructor of class Model
        *
        * This destructor frees memory from the View instance *m_view, the NonPlayerCharacter
        * instance *m_npc, and the SceneObject instance *m_sObject
        *
        */
	~Model();

	/**
        * @brief Sets the reference to View
        *
        * This function references the View class pointer to the class created within Controller
        *
        * @param View *t_view - View
        * @return void
        */
	void SetView(View *t_view);

	/**
        * @brief Sets the size of m_goArray
        *
        * This function sets the size of the GameObject array
        *
        * @param int t_size - size of GO array
        * @return void
        */
	void SetGOSize(int t_size);

	/**
        * @brief Creates a GameObject
        *
        * Creates a GameObject with specified settings
        *
        * @param const string t_description - Type of GameObject (Player, NPC, Scene)
		* @param int t_index - Array index to store GameObject at
		* @param float t_transformX - X location
		* @param float t_transformY - Y location
		* @param float t_transformZ - Z location
		* @param float t_rotationX - X rotation
		* @param float t_rotationY - Y rotation
		* @param float t_rotationZ - Z rotation
		* @param string t_modelPath - Location of GameObject model
		* @param string t_aiPath - Location of GameObject AI
		* @param int t_health - Health of GameObject
		* @param bool t_hostility - State of GameObject's hostility towards player
		* @param bool t_staticity - State of GameObject's staticity (whether it is affected by physics or not)
        * @return void
        */
	void CreateGameObject(const string t_description, int t_index, float t_transformX, float t_transformY, float t_transformZ, float t_rotationX, float t_rotationY, float t_rotationZ, string t_modelPath, string t_aiPath, int t_health, bool t_hostility, bool t_staticity);

	/**
        * @brief Loads in models
        *
        * This function passes a string on towards the loader, to load GameObject models. 
		*
        * @param string mPath - location of GameObject's model
		* @param int iNdex - Array index of GameObject
        * @return void
        */
	void LoadModels(string t_modelPath, int t_index);


	//////////////////////
	//Checkpoint system here
	//Will need to save Player stats, NPC stats and likely SceneObject stats too
	//////////////////////

private:
	/** 
	 *	Class Member
	 *	This variable contains a pointer to an instance of View
	 */
	View *m_view;

	/** 
	 *	Class Member
	 *	This variable is an instance of GameAssetFactory
	 */
	GameAssetFactory m_gAF;

	/** 
	 *	Class Member
	 *	This variable is a double pointer to an instance of GameObject
	 *  and is used as a dynamic array
	 */
	GameObject **m_goArray;

	/** 
	 *	Class Member
	 *	This variable is read in via LUA
	 *  and is used as the size for the m_goArray
	 */
	int m_objectCount;

};

#endif