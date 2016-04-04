#ifndef GameObject_H
#define GameObject_H

#include <string>

using namespace std;

struct Vector3 {float x, y, z;};

class GameObject
{

public:

	/**
        * @brief Default constructor of class GameObject
        *
        * This constructor sets the variables of class GameObject to the default
        * values
        *
        */
	GameObject();

	////////
	//Accessors
	////////

	/**
        * @brief Returns the x transform
        *
        * This function returns the x transform to the client program
        *
        * @return float - m_transform.x
        */
	float TransformX() const;

	/**
        * @brief Returns the y transform
        *
        * This function returns the y transform to the client program
        *
        * @return float - m_transform.y
        */
	float TransformY() const;

	/**
        * @brief Returns the z transform
        *
        * This function returns the z transform to the client program
        *
        * @return float - m_transform.z
        */
	float TransformZ() const;

	/**
        * @brief Returns the x rotation
        *
        * This function returns the x rotation to the client program
        *
        * @return float - m_rotation.x
        */
	float RotationX() const;

	/**
        * @brief Returns the y rotation
        *
        * This function returns the y rotation to the client program
        *
        * @return float - m_rotation.y
        */
	float RotationY() const;

	/**
        * @brief Returns the z rotation
        *
        * This function returns the z rotation to the client program
        *
        * @return float - m_rotation.z
        */
	float RotationZ() const;

	/**
        * @brief Returns the static status
        *
        * This function returns the staticity status of the object to the client program
        *
        * @return bool - m_isStatic
        */
	bool IsStatic() const;

	/**
        * @brief Returns the player status
        *
        * This function returns the player status of the object to the client program
        *
        * @return bool - m_isPlayer
        */
	bool IsPlayer() const;
	
	/**
        * @brief Returns the object's health
        *
        * This function returns the health of the object to the client program
        *
        * @return int - m_objHealth
        */
	int ObjectHealth() const;

	/**
        * @brief Returns the model path
        *
        * This function returns the model path of the object to the client program
        *
        * @return string - m_modelPath
        */
	string ModelPath() const;

	/**
        * @brief Returns the AI path
        *
        * This function returns the AI path of the object to the client program
        *
        * @return string - m_aiPath
        */
	string AIPath() const;

	////////
	//Mutators
	////////

	/**
        * @brief Sets the x transform
        *
        * This function sets the x transform of the GameObject to that supplied
        * by the client program
        *
        * @param float t_transform_x - x transform
        * @return void
        */
	void TransformX(float t_transform_x);

	/**
        * @brief Sets the y transform
        *
        * This function sets the y transform of the GameObject to that supplied
        * by the client program
        *
        * @param float t_transform_y - y transform
        * @return void
        */
	void TransformY(float t_transform_y);

	/**
        * @brief Sets the z transform
        *
        * This function sets the z transform of the GameObject to that supplied
        * by the client program
        *
        * @param float t_transform_z - z transform
        * @return void
        */
	void TransformZ(float t_transform_z);

	/**
        * @brief Sets the x rotation
        *
        * This function sets the x rotation of the GameObject to that supplied
        * by the client program
        *
        * @param float t_rotation_x - x rotation
        * @return void
        */
	void RotationX(float t_rotation_x);

	/**
        * @brief Sets the y rotation
        *
        * This function sets the y rotation of the GameObject to that supplied
        * by the client program
        *
        * @param float t_rotation_y - y rotation
        * @return void
        */
	void RotationY(float t_rotation_y);

	/**
        * @brief Sets the z rotation
        *
        * This function sets the z rotation of the GameObject to that supplied
        * by the client program
        *
        * @param float t_rotation_z - z rotation
        * @return void
        */
	void RotationZ(float t_rotation_z);

	/**
        * @brief Sets the static status
        *
        * This function sets the static status of the GameObject to that supplied
        * by the client program
        *
        * @param bool t_isStatic - static status
        * @return void
        */
	void IsStatic(bool t_isStatic);

	/**
        * @brief Sets the player status
        *
        * This function sets the player status of the GameObject to that supplied
        * by the client program
        *
        * @param bool t_isPlayer - player status
        * @return void
        */
	void IsPlayer(bool t_isPlayer);

	/**
        * @brief Sets the object's health
        *
        * This function sets the health of the GameObject to that supplied
        * by the client program
        *
        * @param bool t_objHealth - object health
        * @return void
        */
	void ObjectHealth(int t_objHealth);

	/**
        * @brief Sets the object model path
        *
        * This function sets the object model path of the GameObject to that supplied
        * by the client program
        *
        * @param string t_modelPath - object model path
        * @return void
        */
	void ModelPath(string t_modelPath);

	/**
        * @brief Sets the object AI path
        *
        * This function sets the object AI path of the GameObject to that supplied
        * by the client program
        *
        * @param string t_aiPath - object AI path
        * @return void
        */
	void AIPath(string t_aiPath);
	
private:

	Vector3 m_transform;
	Vector3 m_rotation;
	bool    m_isStatic;
	bool	m_isPlayer;
	int		m_objHealth;
	string	m_modelPath;
	string	m_aiPath;

};

#endif