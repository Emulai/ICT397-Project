#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player: public GameObject
{
public:
	///Getters
	/**
        * @brief Virtual Transform
        *
        * Returns Player Transform
        *
        * @return Vector3 - Transform
        */
	virtual Vector3 Transform() const;

	/**
        * @brief Virtual TransformX
        *
        * Returns Player TransformX
        *
        * @return float - TransformX
        */
	virtual float TransformX() const;

	/**
        * @brief Virtual TransformY
        *
        * Returns Player TransformY
        *
        * @return float - TransformY
        */
	virtual float TransformY() const;
	
	/**
        * @brief Virtual TransformZ
        *
        * Returns Player TransformZ
        *
        * @return float - TransformZ
        */
	virtual float TransformZ() const;

	/**
        * @brief Virtual Rotation
        *
        * Returns Player Rotation
        *
        * @return Vector3 - Rotation
        */
	virtual Vector3 Rotation() const;

	/**
        * @brief Virtual RotationX
        *
        * Returns Player RotationX
        *
        * @return float - RotationX
        */
	virtual float RotationX() const;

	/**
        * @brief Virtual RotationY
        *
        * Returns Player RotationY
        *
        * @return float - RotationY
        */
	virtual float RotationY() const;

	/**
        * @brief Virtual RotationZ
        *
        * Returns Player RotationZ
        *
        * @return float - RotationZ
        */
	virtual float RotationZ() const;

	/**
        * @brief Virtual ModelPath
        *
        * Returns Player ModelPath
        *
        * @return string - Model Path
        */
	virtual string ModelPath() const;

	/**
        * @brief Virtual AIPath
        *
        * Returns Player AIPath
        *
        * @return string - AI Path
        */
	virtual string AIPath() const;

	/**
        * @brief Virtual Health
        *
        * Returns Player Health
        * @return int - Health
        */
	virtual int Health() const;

	/**
        * @brief Virtual Index
        *
        * Returns Player Index
        *
        * @return int - Index
        */
	virtual int Index() const;

	/**
        * @brief Virtual IsHostile
        *
        * Returns Player Hostility
        *
        * @return bool - Hostility
        */
	virtual bool IsHostile() const;

	/**
        * @brief Virtual Staticity
        *
        * Returns Player Staticity
        *
        * @return bool - Staticity
        */
	virtual bool Staticity() const;

	///Setters
	/**
        * @brief Virtual Transform
        *
        * Sets Player Transform
        *
		* @param Vector3 t_transform
        * @return void
        */
	virtual void Transform(Vector3 t_transform);

	/**
        * @brief Virtual TransformX
        *
        * Sets Player TransformX
        *
		* @param float t_transformX
        * @return void
        */
	virtual void TransformX(float t_transformX);

	/**
        * @brief Virtual TransformY
        *
        * Sets Player TransformY
        *
		* @param float t_transformY
        * @return void
        */
	virtual void TransformY(float t_transformY);

	/**
        * @brief Virtual TransformZ
        *
        * Sets Player TransformZ
        *
		* @param float t_transformZ
        * @return void
        */
	virtual void TransformZ(float t_transformZ);

	/**
        * @brief Virtual Rotation
        *
        * Sets Player Rotation
        *
		* @param Vector3 t_rotation
        * @return void
        */
	virtual void Rotation(Vector3 t_rotation);

	/**
        * @brief Virtual RotationX
        *
        * Sets Player RotationX
        *
		* @param float t_rotationX
        * @return void
        */
	virtual void RotationX(float t_rotationX);

	/**
        * @brief Virtual RotationY
        *
        * Sets Player RotationY
        *
		* @param float t_rotationY
        * @return void
        */
	virtual void RotationY(float t_rotationY);

	/**
        * @brief Virtual RotationZ
        *
        * Sets Player RotationZ
        *
		* @param float t_rotationZ
        * @return void
        */
	virtual void RotationZ(float t_rotationZ);

	/**
        * @brief Virtual ModelPath
        *
        * Sets Player ModelPath
        *
		* @param string t_modelPath
        * @return void
        */
	virtual void ModelPath(string t_modelPath);

	/**
        * @brief Virtual AIPath
        *
        * Sets Player AIPath
        *
		* @param string t_aiPath
        * @return void
        */
	virtual void AIPath(string t_aiPath);

	/**
        * @brief Virtual Health
        *
        * Sets Player Health
        *
		* @param int t_health
        * @return void
        */
	virtual void Health(int t_health);

	/**
        * @brief Virtual Index
        *
        * Sets Player Index
        *
		* @param int t_index
        * @return void
        */
	virtual void Index(int t_index);

	/**
        * @brief Virtual IsHostile
        *
        * Sets Player Hostility
        *
		* @param bool t_hostility
        * @return void
        */
	virtual void IsHostile(bool t_hostility);

	/**
        * @brief Virtual Staticity
        *
        * Sets Player Staticity
        *
		* @param bool t_staticity
        * @return void
        */
	virtual void Staticity(bool t_staticity);

	/**
        * @brief Destructor
        *
        */
	virtual ~Player() {};

private:
	
	/** 
	 *	Class Member
	 *	These variables hold Player Transforms and Rotation
	 */
	Vector3 m_transform, m_rotation;

	/** 
	 *	Class Member
	 *	This variable holds Player Model Path
	 */
	string m_modelPath;

	/** 
	 *	Class Member
	 *	These variables hold Player Health and Index
	 */
	int m_health, m_index;

};

#endif