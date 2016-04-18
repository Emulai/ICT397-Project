#ifndef MODEL_H
#define MODEL_H

#include <cstdio>
#include <iostream>
#include <lua.hpp>
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

	void SetGOSize(int t_size);

	void CreateGameObject(const string t_description, int t_index, float t_transformX, float t_transformY, float t_transformZ, float t_rotationX, float t_rotationY, float t_rotationZ, string t_modelPath, string t_aiPath, int t_health, bool t_hostility, bool t_staticity);

	/**
        * @brief Runs the ObjectType test
        *
        * This function tests all functions within ObjectType.h and GameObject.h to ensure they
        * are in working order
        *
        * @return void
        */
	void ObjectTypeTest();

	void LoadModels(string mPath, int iNdex);

	/**
        * @brief Passes model references to View
        *
        * This function passes the model reference numbers for the player, and for each NPC and
        * SceneObject to View->Render for rendering
        *
        * @return void
        */
	void SendToView();
	//int multiply(int a, int b);
	//int cpp_Multiply(lua_State* luaVM);
	void LuaSettings();	

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

	GameObject **m_goArray;

	bool m_tested;

	Vector3 m_test;

	int m_objectCount;

};

#endif