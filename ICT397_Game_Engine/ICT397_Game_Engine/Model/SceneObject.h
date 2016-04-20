#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "GameObject.h"

class SceneObject: public GameObject
{
public:

	///Getters
	/**
        * @brief Virtual Transform
        *
        * Returns SceneObject Transform
        *
        * @return Vector3 - Transform
        */
	virtual Vector3 Transform() const;

	/**
        * @brief Virtual TransformX
        *
        * Returns SceneObject TransformX
        *
        * @return float - TransformX
        */
	virtual float TransformX() const;

	/**
        * @brief Virtual TransformY
        *
        * Returns SceneObject TransformY
        *
        * @return float - TransformY
        */
	virtual float TransformY() const;

	/**
        * @brief Virtual TransformZ
        *
        * Returns SceneObject TransformZ
        *
        * @return float - TransformZ
        */
	virtual float TransformZ() const;

	/**
        * @brief Virtual Rotation
        *
        * Returns SceneObject Rotation
        *
        * @return Vector3 - Rotation
        */
	virtual Vector3 Rotation() const;

	/**
        * @brief Virtual RotationX
        *
        * Returns SceneObject RotationX
        *
        * @return float - RotationX
        */
	virtual float RotationX() const;

	/**
        * @brief Virtual RotationY
        *
        * Returns SceneObject RotationY
        *
        * @return float - RotationY
        */
	virtual float RotationY() const;

	/**
        * @brief Virtual RotationZ
        *
        * Returns SceneObject RotationZ
        *
        * @return float - RotationZ
        */
	virtual float RotationZ() const;

	/**
        * @brief Virtual ModelPath
        *
        * Returns SceneObject ModelPath
        *
        * @return string - Model Path
        */
	virtual string ModelPath() const;

	/**
        * @brief Virtual AIPath
        *
        * Returns SceneObject AIPath
        *
        * @return string - AI Path
        */
	virtual string AIPath() const;

	/**
        * @brief Virtual Health
        *
        * Returns SceneObject Health
        * @return int - Health
        */
	virtual int Health() const;

	/**
        * @brief Virtual Index
        *
        * Returns SceneObject Index
        *
        * @return int - Index
        */
	virtual int Index() const;

	/**
        * @brief Virtual IsHostile
        *
        * Returns SceneObject Hostility
        *
        * @return bool - Hostility
        */
	virtual bool IsHostile() const;

	/**
        * @brief Virtual Staticity
        *
        * Returns SceneObject Staticity
        *
        * @return bool - Staticity
        */
	virtual bool Staticity() const;

	///Setters
	/**
        * @brief Virtual Transform
        *
        * Sets SceneObject Transform
        *
		* @param Vector3 t_transform
        * @return void
        */
	virtual void Transform(Vector3 t_transform);

	/**
        * @brief Virtual TransformX
        *
        * Sets SceneObject TransformX
        *
		* @param float t_transformX
        * @return void
        */
	virtual void TransformX(float t_transformX);

	/**
        * @brief Virtual TransformY
        *
        * Sets SceneObject TransformY
        *
		* @param float t_transformY
        * @return void
        */
	virtual void TransformY(float t_transformY);

	/**
        * @brief Virtual TransformZ
        *
        * Sets SceneObject TransformZ
        *
		* @param float t_transformZ
        * @return void
        */
	virtual void TransformZ(float t_transformZ);

	/**
        * @brief Virtual Rotation
        *
        * Sets SceneObject Rotation
        *
		* @param Vector3 t_rotation
        * @return void
        */
	virtual void Rotation(Vector3 t_rotation);

	/**
        * @brief Virtual RotationX
        *
        * Sets SceneObject RotationX
        *
		* @param float t_rotationX
        * @return void
        */
	virtual void RotationX(float t_rotationX);
	
	/**
        * @brief Virtual RotationY
        *
        * Sets SceneObject RotationY
        *
		* @param float t_rotationY
        * @return void
        */
	virtual void RotationY(float t_rotationY);

	/**
        * @brief Virtual RotationZ
        *
        * Sets SceneObject RotationZ
        *
		* @param float t_rotationZ
        * @return void
        */
	virtual void RotationZ(float t_rotationZ);

	/**
        * @brief Virtual ModelPath
        *
        * Sets SceneObject ModelPath
        *
		* @param string t_modelPath
        * @return void
        */
	virtual void ModelPath(string t_modelPath);

	/**
        * @brief Virtual AIPath
        *
        * Sets SceneObject AIPath
        *
		* @param string t_aiPath
        * @return void
        */
	virtual void AIPath(string t_aiPath);

	/**
        * @brief Virtual Health
        *
        * Sets SceneObject Health
        *
		* @param int t_health
        * @return void
        */
	virtual void Health(int t_health);

	/**
        * @brief Virtual Index
        *
        * Sets SceneObject Index
        *
		* @param int t_index
        * @return void
        */
	virtual void Index(int t_index);

	/**
        * @brief Virtual IsHostile
        *
        * Sets SceneObject Hostility
        *
		* @param bool t_hostility
        * @return void
        */
	virtual void IsHostile(bool t_hostility);

	/**
        * @brief Virtual Staticity
        *
        * Sets SceneObject Staticity
        *
		* @param bool t_staticity
        * @return void
        */
	virtual void Staticity(bool t_staticity);

	/**
        * @brief Destructor
        *
        */
	~SceneObject() {};

private:

	/** 
	 *	Class Member
	 *	These variables hold SceneObject Transforms and Rotations
	 */
	Vector3 m_transform, m_rotation;

	/** 
	 *	Class Member
	 *	This variable holds SceneObject Model Path
	 */
	string m_modelPath;

	/** 
	 *	Class Member
	 *	This variable holds SceneObject Index
	 */
	int m_index;

	/** 
	 *	Class Member
	 *	This variable holds SceneObject Staticity
	 */
	bool m_staticity;

};

#endif