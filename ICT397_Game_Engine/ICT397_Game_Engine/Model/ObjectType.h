#ifndef OBJECTTYPE_H
#define OBJECTTYPE_H

#include <string>
#include "GameObject.h"

class Player: public GameObject
{
public:

	/**
        * @brief Default constructor of class Player
        *
        * This constructor sets the variables of class Player to the default
        * values
        *
        */
	Player();

	//////////
	//Accessors
	//////////

	/**
        * @brief Returns the object's health
        *
        * This function returns the health of the player to the client program
        *
        * @return int - m_playerHealth
        */
	int Health() const;

	//////////
	//Mutators
	//////////

	/**
        * @brief Sets the object's health
        *
        * This function sets the health of the player to that supplied
        * by the client program
        *
        * @param int t_health - player health
        * @return void
        */
	void Health(int t_health);

private:

	//Player stats
	int m_playerHealth;

};



class NonPlayerCharacter: public GameObject
{
public:

	/**
        * @brief Default constructor of class NonPlayerCharacter
        *
        * This constructor sets the variables of class NonPlayerCharacter to the default
        * values
        *
        */
	NonPlayerCharacter();

	//////////
	//Accessors
	//////////

	/**
        * @brief Returns the NPC's hostility
        *
        * This function returns the hostility of the NPC towards the player to the client program
        *
        * @return bool - m_npcIsHostile
        */
	bool IsHostile() const;

	/**
        * @brief Returns the NPC's health
        *
        * This function returns the health of the NPC to the client program
        *
        * @return int - m_npcHealth
        */
	int Health() const;

	/**
        * @brief Returns the AI path
        *
        * This function returns the AI path of the NPC to the client program
        *
        * @return string - m_npcAIPath
        */
	string AIPath() const;

	//////////
	//Mutators
	//////////

	/**
        * @brief Sets the NPC's Hostility
        *
        * This function sets the hostility of the NPC toward the player to that supplied
        * by the client program
        *
        * @param bool t_hostility - NPC hostility
        * @return void
        */
	void IsHostile(bool t_hostility);

	/**
        * @brief Sets the NPC's health
        *
        * This function sets the health of the NPC to that supplied
        * by the client program
        *
        * @param int t_health - NPC health
        * @return void
        */
	void Health(int t_health);

	/**
        * @brief Sets the NPC AI path
        *
        * This function sets the AI path of the NPC to that supplied
        * by the client program
        *
        * @param string t_aiPath - NPC AI path
        * @return void
        */
	void AIPath(string t_aiPath);

private:

	//NPC stats
	bool	m_npcIsHostile;
	int		m_npcHealth;
	string	m_npcAIPath;

};



class SceneObject: public GameObject
{
public:

	/**
        * @brief Default constructor of class SceneObject
        *
        * This constructor sets the variables of class SceneObject to the default
        * values
        *
        */
	SceneObject();

	///////////
	//Accessors
	///////////


	/**
        * @brief Returns the static status
        *
        * This function returns the staticity status of the object to the client program
        *
        * @return bool - m_isStatic
        */
	bool Staticity() const;

	///////////
	//Mutators
	///////////

	/**
        * @brief Sets the static status
        *
        * This function sets the static status of the GameObject to that supplied
        * by the client program
        *
        * @param bool t_isStatic - static status
        * @return void
        */
	void Staticity(bool t_static);

private:

	bool m_isStatic;

};

#endif