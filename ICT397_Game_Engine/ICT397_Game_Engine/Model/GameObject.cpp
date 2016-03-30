#include "GameObject.h"

GameObject::GameObject()
{

}

/////////
//Accessors
/////////

float GameObject::TransformX() const
{
	return m_transform.x;
}

float GameObject::TransformY() const
{
	return m_transform.y;
}

float GameObject::TransformZ() const
{
	return m_transform.z;
}

float GameObject::RotationX() const
{
	return m_rotation.x;
}

float GameObject::RotationY() const
{
	return m_rotation.y;
}

float GameObject::RotationZ() const
{
	return m_rotation.z;
}

bool GameObject::IsStatic() const
{
	return m_isStatic;
}

bool GameObject::IsPlayer() const
{
	return m_isPlayer;
}

int GameObject::ObjectHealth() const
{
	return m_objHealth;
}

string GameObject::ModelPath() const
{
	return m_modelPath;
}

string GameObject::AIPath() const
{
	return m_aiPath;
}

/////////
//Mutators
/////////

void GameObject::TransformX(float t_transform)
{
	m_transform.x = t_transform;
}

void GameObject::TransformY(float t_transform)
{
	m_transform.y = t_transform;
}

void GameObject::TransformZ(float t_transform)
{
	m_transform.z = t_transform;
}

void GameObject::RotationX(float t_rotation)
{
	m_rotation.x = t_rotation;
}

void GameObject::RotationY(float t_rotation)
{
	m_rotation.y = t_rotation;
}

void GameObject::RotationZ(float t_rotation)
{
	m_rotation.z = t_rotation;
}

void GameObject::IsStatic(bool t_isStatic)
{
	m_isStatic = t_isStatic;
}

void GameObject::IsPlayer(bool t_isPlayer)
{
	m_isPlayer = t_isPlayer;
}

void GameObject::ObjectHealth(int t_objHealth)
{
	m_objHealth = t_objHealth;
}

void GameObject::ModelPath(string t_modelPath)
{
	m_modelPath = t_modelPath;
}

void GameObject::AIPath(string t_aiPath)
{
	m_aiPath = t_aiPath;
}