#ifndef MODEL_H
#define MODEL_H

#include <iostream>

#include "GameAssetFactory.h"
#include "..\View\View.h"

using namespace std;


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
        * @brief Runs the ObjectType test
        *
        * This function tests all functions within ObjectType.h and GameObject.h to ensure they
        * are in working order
        *
        * @return void
        */
	void ObjectTypeTest();

	/**
        * @brief Passes model references to View
        *
        * This function passes the model reference numbers for the player, and for each NPC and
        * SceneObject to View->Render for rendering
        *
        * @return void
        */
	void SendToView();

	GameObject* CreateGameObject(const string t_description);

	//////////////////////
	//Checkpoint system here
	//Will need to save Player stats, NPC stats and likely SceneObject stats too
	//////////////////////

private:

	/**
        * @brief Obtains data from LUA
        *
        * This function uses LUA scripting to retrieve data for the Player, NonPlayerCharacter
        * and SceneObject classes, initialising them
        *
        * @return void
        */
	//void SetWithLUA()

	View *m_view;

	GameAssetFactory m_gAF;

	bool m_tested;

	Vector3 m_test;

	int m_npcCount;
	int m_sOCount;

};

#endif