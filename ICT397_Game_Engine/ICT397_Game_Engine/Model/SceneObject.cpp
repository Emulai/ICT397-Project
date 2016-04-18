#include "SceneObject.h"

Vector3 SceneObject::Transform() const
{
	return m_transform;
}

float SceneObject::TransformX() const
{
	return m_transform.x;
}

float SceneObject::TransformY() const
{
	return m_transform.y;
}

float SceneObject::TransformZ() const
{
	return m_transform.z;
}

Vector3 SceneObject::Rotation() const
{
	return m_rotation;
}

float SceneObject::RotationX() const
{
	return m_rotation.x;
}

float SceneObject::RotationY() const
{
	return m_rotation.y;
}

float SceneObject::RotationZ() const
{
	return m_rotation.z;
}

string SceneObject::ModelPath() const
{
	return m_modelPath;
}

string SceneObject::AIPath() const
{
	cout << "Objects can't be intelligent!" << endl;
	return "";
}

int SceneObject::Health() const
{
	cout << "Objects don't have health! Although they kinda do..." << endl;
	return 0;
}

int SceneObject::Index() const
{
	return m_index;
}

bool SceneObject::IsHostile() const
{
	cout << "Do you really think this box/rock hates you?" << endl;
	return false;
}

bool SceneObject::Staticity() const
{
	return m_staticity;
}

//Setters

void SceneObject::Transform(Vector3 t_transform)
{
	m_transform = t_transform;
}

void SceneObject::TransformX(float t_transformX)
{
	m_transform.x = t_transformX;
}

void SceneObject::TransformY(float t_transformY)
{
	m_transform.y = t_transformY;
}

void SceneObject::TransformZ(float t_transformZ)
{
	m_transform.z = t_transformZ;
}

void SceneObject::Rotation(Vector3 t_rotation)
{
	m_rotation = t_rotation;
}

void SceneObject::RotationX(float t_rotationX)
{
	m_rotation.x = t_rotationX;
}

void SceneObject::RotationY(float t_rotationY)
{
	m_rotation.y = t_rotationY;
}

void SceneObject::RotationZ(float t_rotationZ)
{
	m_rotation.z = t_rotationZ;
}

void SceneObject::ModelPath(string t_modelPath)
{
	m_modelPath = t_modelPath;
}

void SceneObject::AIPath(string t_aiPath)
{
	cout << "You can't give boxes intelligence or they'll hate you!" << endl;
}

void SceneObject::Health(int t_health)
{
	cout << "These are some seriously unhealthy boxes. Because they Don't. Have. Health." << endl;
}

void SceneObject::Index(int t_index)
{
	m_index = t_index;
}

void SceneObject::IsHostile(bool t_hostility)
{
	cout << "Did you annoy a toaster? Seriously, objects DON'T hate you." << endl;
}

void SceneObject::Staticity(bool t_staticity)
{
	m_staticity = t_staticity;
}