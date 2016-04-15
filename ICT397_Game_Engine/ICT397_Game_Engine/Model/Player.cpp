#include "Player.h"

Vector3 Player::Transform() const
{
	return m_transform;
}

float Player::TransformX() const
{
	return m_transform.x;
}

float Player::TransformY() const
{
	return m_transform.y;
}

float Player::TransformZ() const
{
	return m_transform.z;
}

Vector3 Player::Rotation() const
{
	return m_rotation;
}

float Player::RotationX() const
{
	return m_rotation.x;
}

float Player::RotationY() const
{
	return m_rotation.y;
}

float Player::RotationZ() const
{
	return m_rotation.z;
}

string Player::ModelPath() const
{
	return m_modelPath;
}

string Player::AIPath() const
{
	cout << "Player has no AI!" << endl;
	return "";
}

int Player::Health() const
{
	return m_health;
}

bool Player::IsHostile() const
{
	cout << "Player cannot be hostile towards self!" << endl;
	return false;
}

bool Player::Staticity() const
{
	cout << "Player cannot be static!" << endl;
	return false;
}

//Setters

void Player::Transform(Vector3 t_transform)
{
	m_transform = t_transform;
}

void Player::TransformX(float t_transformX)
{
	m_transform.x = t_transformX;
}

void Player::TransformY(float t_transformY)
{
	m_transform.y = t_transformY;
}

void Player::TransformZ(float t_transformZ)
{
	m_transform.z = t_transformZ;
}

void Player::Rotation(Vector3 t_rotation)
{
	m_rotation = t_rotation;
}

void Player::RotationX(float t_rotationX)
{
	m_rotation.x = t_rotationX;
}

void Player::RotationY(float t_rotationY)
{
	m_rotation.y = t_rotationY;
}

void Player::RotationZ(float t_rotationZ)
{
	m_rotation.z = t_rotationZ;
}

void Player::ModelPath(string t_modelPath)
{
	m_modelPath = t_modelPath;
}

void Player::AIPath(string t_aiPath)
{
	cout << "Player does not have an AI Path." << endl;
}

void Player::Health(int t_health)
{
	m_health = t_health;
}

void Player::IsHostile(bool t_hostility)
{
	cout << "Player cannot be hostile towards self!" << endl;
}

void Player::Staticity(bool t_staticity)
{
	cout << "Player cannot be static!" << endl;
}