#ifndef NONPLAYERCHARACTER_H
#define NONPLAYERCHARACTER_H

#include "GameObject.h"

class NonPlayerCharacter: public GameObject
{
public:
	///Getters
	/**
        * @brief Virtual Transform
        *
        * Returns NonPlayerCharacter Transform
        *
        * @return Vector3 - Transform
        */
	virtual Vector3 Transform() const;

	/**
        * @brief Virtual TransformX
        *
        * Returns NonPlayerCharacter TransformX
        *
        * @return float - TransformX
        */
	virtual float TransformX() const;

	/**
        * @brief Virtual TransformY
        *
        * Returns NonPlayerCharacter TransformY
        *
        * @return float - TransformY
        */
	virtual float TransformY() const;

	/**
        * @brief Virtual TransformZ
        *
        * Returns NonPlayerCharacter TransformZ
        *
        * @return float - TransformZ
        */
	virtual float TransformZ() const;

	/**
        * @brief Virtual Rotation
        *
        * Returns NonPlayerCharacter Rotation
        *
        * @return Vector3 - Rotation
        */
	virtual Vector3 Rotation() const;

	/**
        * @brief Virtual RotationX
        *
        * Returns NonPlayerCharacter RotationX
        *
        * @return float - RotationX
        */
	virtual float RotationX() const;

	/**
        * @brief Virtual RotationY
        *
        * Returns NonPlayerCharacter RotationY
        *
        * @return float - RotationY
        */
	virtual float RotationY() const;

	/**
        * @brief Virtual RotationZ
        *
        * Returns NonPlayerCharacter RotationZ
        *
        * @return float - RotationZ
        */
	virtual float RotationZ() const;

	/**
        * @brief Virtual ModelPath
        *
        * Returns NonPlayerCharacter ModelPath
        *
        * @return string - Model Path
        */
	virtual string ModelPath() const;

	/**
        * @brief Virtual AIPath
        *
        * Returns NonPlayerCharacter AIPath
        *
        * @return string - AI Path
        */
	virtual string AIPath() const;

	/**
        * @brief Virtual Health
        *
        * Returns NonPlayerCharacter Health
        * @return int - Health
        */
	virtual int Health() const;

	/**
        * @brief Virtual Index
        *
        * Returns NonPlayerCharacter Index
        *
        * @return int - Index
        */
	virtual int Index() const;

	/**
        * @brief Virtual IsHostile
        *
        * Returns NonPlayerCharacter Hostility
        *
        * @return bool - Hostility
        */
	virtual bool IsHostile() const;

	/**
        * @brief Virtual Staticity
        *
        * Returns NonPlayerCharacter Staticity
        *
        * @return bool - Staticity
        */
	virtual bool Staticity() const;

	///Setters
	/**
        * @brief Virtual Transform
        *
        * Sets NonPlayerCharacter Transform
        *
		* @param Vector3 t_transform
        * @return void
        */
	virtual void Transform(Vector3 t_transform);

	/**
        * @brief Virtual TransformX
        *
        * Sets NonPlayerCharacter TransformX
        *
		* @param float t_transformX
        * @return void
        */
	virtual void TransformX(float t_transformX);

	/**
        * @brief Virtual TransformY
        *
        * Sets NonPlayerCharacter TransformY
        *
		* @param float t_transformY
        * @return void
        */
	virtual void TransformY(float t_transformY);

	/**
        * @brief Virtual TransformZ
        *
        * Sets NonPlayerCharacter TransformZ
        *
		* @param float t_transformZ
        * @return void
        */
	virtual void TransformZ(float t_transformZ);

	/**
        * @brief Virtual Rotation
        *
        * Sets NonPlayerCharacter Rotation
        *
		* @param Vector3 t_rotation
        * @return void
        */
	virtual void Rotation(Vector3 t_rotation);

	/**
        * @brief Virtual RotationX
        *
        * Sets NonPlayerCharacter RotationX
        *
		* @param float t_rotationX
        * @return void
        */
	virtual void RotationX(float t_rotationX);
	
	/**
        * @brief Virtual RotationY
        *
        * Sets NonPlayerCharacter RotationY
        *
		* @param float t_rotationY
        * @return void
        */
	virtual void RotationY(float t_rotationY);

	/**
        * @brief Virtual RotationZ
        *
        * Sets NonPlayerCharacter RotationZ
        *
		* @param float t_rotationZ
        * @return void
        */
	virtual void RotationZ(float t_rotationZ);

	/**
        * @brief Virtual ModelPath
        *
        * Sets NonPlayerCharacter ModelPath
        *
		* @param string t_modelPath
        * @return void
        */
	virtual void ModelPath(string t_modelPath);

	/**
        * @brief Virtual AIPath
        *
        * Sets NonPlayerCharacter AIPath
        *
		* @param string t_aiPath
        * @return void
        */
	virtual void AIPath(string t_aiPath);

	/**
        * @brief Virtual Health
        *
        * Sets NonPlayerCharacter Health
        *
		* @param int t_health
        * @return void
        */
	virtual void Health(int t_health);

	/**
        * @brief Virtual Index
        *
        * Sets NonPlayerCharacter Index
        *
		* @param int t_index
        * @return void
        */
	virtual void Index(int t_index);

	/**
        * @brief Virtual IsHostile
        *
        * Sets NonPlayerCharacter Hostility
        *
		* @param bool t_hostility
        * @return void
        */
	virtual void IsHostile(bool t_hostility);

	/**
        * @brief Virtual Staticity
        *
        * Sets NonPlayerCharacter Staticity
        *
		* @param bool t_staticity
        * @return void
        */
	virtual void Staticity(bool t_staticity);


	/**
        * @brief Destructor
        *
        */
	~NonPlayerCharacter() {};

private:
	
	/** 
	 *	Class Member
	 *	These variables hold NonPlayerCharacter Transforms and Rotations
	 */
	Vector3 m_transform, m_rotation;

	/** 
	 *	Class Member
	 *	These variables hold NonPlayerCharacter Model and AI Paths
	 */
	string m_modelPath, m_aiPath;

	/** 
	 *	Class Member
	 *	These variables hold NonPlayerCharacter Health and Index
	 */
	int m_health, m_index;

	/** 
	 *	Class Member
	 *	This variable holds NonPlayerCharacter Hostility
	 */
	bool m_hostility;

};

#endif