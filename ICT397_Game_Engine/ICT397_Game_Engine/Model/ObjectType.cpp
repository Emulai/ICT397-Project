#include "ObjectType.h"

/////
//PLAYER CLASS
/////

Player::Player()
{
	m_playerHealth = 100;
}

//////////
//Accessors
//////////

int Player::Health() const
{
	return m_playerHealth;
}

//////////
//Mutators
//////////

void Player::Health(int t_health)
{
	m_playerHealth = t_health;
}



/////
//NPC CLASS
/////

NonPlayerCharacter::NonPlayerCharacter()
{
	m_npcIsHostile = false;
	m_npcHealth = 100;
	m_npcAIPath = "";
}

//////////
//Accessors
//////////

bool NonPlayerCharacter::IsHostile() const
{
	return m_npcIsHostile;
}

int NonPlayerCharacter::Health() const
{
	return m_npcHealth;
}

string NonPlayerCharacter::AIPath() const
{
	return m_npcAIPath;
}

//////////
//Mutators
//////////

void NonPlayerCharacter::IsHostile(bool t_hostility)
{
	m_npcIsHostile = t_hostility;
}

void NonPlayerCharacter::Health(int t_health)
{
	m_npcHealth = t_health;
}

void NonPlayerCharacter::AIPath(string t_aiPath)
{
	m_npcAIPath = t_aiPath;
}



//////
//SCENEOBJECT CLASS
//////

SceneObject::SceneObject()
{
	m_isStatic = true;
}

/////////
//Accessors
/////////

bool SceneObject::Staticity() const
{
	return m_isStatic;
}

/////////
//Mutators
/////////

void SceneObject::Staticity(bool t_static)
{
	m_isStatic = t_static;
}