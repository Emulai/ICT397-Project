#include "NonPlayerCharacter.h"

Vector3 NonPlayerCharacter::Transform() const
{
	return m_transform;
}

float NonPlayerCharacter::TransformX() const
{
	return m_transform.x;
}

float NonPlayerCharacter::TransformY() const
{
	return m_transform.y;
}

float NonPlayerCharacter::TransformZ() const
{
	return m_transform.z;
}

Vector3 NonPlayerCharacter::Rotation() const
{
	return m_rotation;
}

float NonPlayerCharacter::RotationX() const
{
	return m_rotation.x;
}

float NonPlayerCharacter::RotationY() const
{
	return m_rotation.y;
}

float NonPlayerCharacter::RotationZ() const
{
	return m_rotation.z;
}

string NonPlayerCharacter::ModelPath() const
{
	return m_modelPath;
}

string NonPlayerCharacter::AIPath() const
{
	return m_aiPath;
}

int NonPlayerCharacter::Health() const
{
	return m_health;
}

int NonPlayerCharacter::Index() const
{
	return m_index;
}

bool NonPlayerCharacter::IsHostile() const
{
	return m_hostility;
}

bool NonPlayerCharacter::Staticity() const
{
	cout << "NPC cannot be static, that'd be awkward..." << endl;
	return false;
}

//Setters

void NonPlayerCharacter::Transform(Vector3 t_transform)
{
	m_transform = t_transform;
}

void NonPlayerCharacter::TransformX(float t_transformX)
{
	m_transform.x = t_transformX;
}

void NonPlayerCharacter::TransformY(float t_transformY)
{
	m_transform.y = t_transformY;
}

void NonPlayerCharacter::TransformZ(float t_transformZ)
{
	m_transform.z = t_transformZ;
}

void NonPlayerCharacter::Rotation(Vector3 t_rotation)
{
	m_rotation = t_rotation;
}

void NonPlayerCharacter::RotationX(float t_rotationX)
{
	m_rotation.x = t_rotationX;
}

void NonPlayerCharacter::RotationY(float t_rotationY)
{
	m_rotation.y = t_rotationY;
}

void NonPlayerCharacter::RotationZ(float t_rotationZ)
{
	m_rotation.z = t_rotationZ;
}

void NonPlayerCharacter::ModelPath(string t_modelPath)
{
	m_modelPath = t_modelPath;
}

void NonPlayerCharacter::AIPath(string t_aiPath)
{
	m_aiPath = t_aiPath;
}

void NonPlayerCharacter::Health(int t_health)
{
	m_health = t_health;
}

void NonPlayerCharacter::Index(int t_index)
{
	m_index = t_index;
}

void NonPlayerCharacter::IsHostile(bool t_hostility)
{
	m_hostility = t_hostility;
}

void NonPlayerCharacter::Staticity(bool t_staticity)
{
	cout << "NPCs can't be static! RIDICULOUS!" << endl;
}