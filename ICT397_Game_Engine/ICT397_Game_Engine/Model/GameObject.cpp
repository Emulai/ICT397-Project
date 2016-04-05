#include "GameObject.h"

GameObject::GameObject()
{
	m_transform.x = 0.0f;
	m_transform.y = 0.0f;
	m_transform.z = 0.0f;

	m_rotation.x = 0.0f;
	m_rotation.y = 0.0f;
	m_rotation.z = 0.0f;

	m_modelReference = -1;
}

/////////
//Accessors
/////////

Vector3 GameObject::Transform() const
{
	return m_transform;
}

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

Vector3 GameObject::Rotation() const
{
	return m_rotation;
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

int GameObject::ModelReference() const
{
	return m_modelReference;
}

/////////
//Mutators
/////////

void GameObject::Transform(Vector3 t_transform)
{
	m_transform = t_transform;
}

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

void GameObject::Rotation(Vector3 t_rotation)
{
	m_rotation = t_rotation;
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

void GameObject::ModelReference(int t_modelPath)
{
	m_modelReference = t_modelPath;
}