#ifndef GameObject_H
#define GameObject_H

#include <iostream>
#include <string>

using namespace std;

typedef struct Vector3 {float x, y, z;} Vector3;

class GameObject
{
public:
	///Getters
	/**
        * @brief Pure virtual Transform
        *
        * Pure virtual to be implemented by inherited
        *
        * @return Vector3 - Transform
        */
	virtual Vector3 Transform() const = 0;

	/**
        * @brief Pure virtual TransformX
        *
        * Pure virtual to be implemented by inherited
        *
        * @return float - TransformX
        */
	virtual float TransformX() const = 0;

	/**
        * @brief Pure virtual TransformY
        *
        * Pure virtual to be implemented by inherited
        *
        * @return float - TransformY
        */
	virtual float TransformY() const = 0;

	/**
        * @brief Pure virtual TransformZ
        *
        * Pure virtual to be implemented by inherited
        *
        * @return float - TransformZ
        */
	virtual float TransformZ() const = 0;

	/**
        * @brief Pure virtual Rotation
        *
        * Pure virtual to be implemented by inherited
        *
        * @return Vector3 - Rotation
        */
	virtual Vector3 Rotation() const = 0;

	/**
        * @brief Pure virtual RotationX
        *
        * Pure virtual to be implemented by inherited
        *
        * @return float - RotationX
        */
	virtual float RotationX() const = 0;

	/**
        * @brief Pure virtual RotationY
        *
        * Pure virtual to be implemented by inherited
        *
        * @return float - RotationY
        */
	virtual float RotationY() const = 0;

	/**
        * @brief Pure virtual RotationZ
        *
        * Pure virtual to be implemented by inherited
        *
        * @return float - RotationZ
        */
	virtual float RotationZ() const = 0;

	/**
        * @brief Pure virtual ModelPath
        *
        * Pure virtual to be implemented by inherited
        *
        * @return string - Model Path
        */
	virtual string ModelPath() const = 0;

	/**
        * @brief Pure virtual AIPath
        *
        * Pure virtual to be implemented by inherited
        *
        * @return string - AI Path
        */
	virtual string AIPath() const = 0;

	/**
        * @brief Pure virtual Health
        *
        * Pure virtual to be implemented by inherited
        *
        * @return int - Health
        */
	virtual int Health() const = 0;

	/**
        * @brief Pure virtual Index
        *
        * Pure virtual to be implemented by inherited
        *
        * @return int - Index
        */
	virtual int Index() const = 0;

	/**
        * @brief Pure virtual IsHostile
        *
        * Pure virtual to be implemented by inherited
        *
        * @return bool - Hostility
        */
	virtual bool IsHostile() const = 0;

	/**
        * @brief Pure virtual Staticity
        *
        * Pure virtual to be implemented by inherited
        *
        * @return bool - Staticity
        */
	virtual bool Staticity() const = 0;

	///Setters

	/**
        * @brief Pure virtual Transform
        *
        * Pure virtual to be implemented by inherited
        *
		* @param Vector3 t_transform
        * @return void
        */
	virtual void Transform(Vector3 t_transform) = 0;

	/**
        * @brief Pure virtual TransformX
        *
        * Pure virtual to be implemented by inherited
        *
		* @param float t_transformX
        * @return void
        */
	virtual void TransformX(float t_transformX) = 0;

	/**
        * @brief Pure virtual TransformY
        *
        * Pure virtual to be implemented by inherited
        *
		* @param float t_transformY
        * @return void
        */
	virtual void TransformY(float t_transformY) = 0;

	/**
        * @brief Pure virtual TransformZ
        *
        * Pure virtual to be implemented by inherited
        *
		* @param float t_transformZ
        * @return void
        */
	virtual void TransformZ(float t_transformZ) = 0;

	/**
        * @brief Pure virtual Rotation
        *
        * Pure virtual to be implemented by inherited
        *
		* @param Vector3 t_rotation
        * @return void
        */
	virtual void Rotation(Vector3 t_rotation) = 0;

	/**
        * @brief Pure virtual RotationX
        *
        * Pure virtual to be implemented by inherited
        *
		* @param float t_rotationX
        * @return void
        */
	virtual void RotationX(float t_rotationX) = 0;

	/**
        * @brief Pure virtual RotationY
        *
        * Pure virtual to be implemented by inherited
        *
		* @param float t_rotationY
        * @return void
        */
	virtual void RotationY(float t_rotationY) = 0;

	/**
        * @brief Pure virtual RotationZ
        *
        * Pure virtual to be implemented by inherited
        *
		* @param float t_rotationZ
        * @return void
        */
	virtual void RotationZ(float t_rotationZ) = 0;

	/**
        * @brief Pure virtual ModelPath
        *
        * Pure virtual to be implemented by inherited
        *
		* @param string t_modelPath
        * @return void
        */
	virtual void ModelPath(string t_modelPath) = 0;

	/**
        * @brief Pure virtual AIPath
        *
        * Pure virtual to be implemented by inherited
        *
		* @param string t_aiPath
        * @return void
        */
	virtual void AIPath(string t_aiPath) = 0;

	/**
        * @brief Pure virtual Health
        *
        * Pure virtual to be implemented by inherited
        *
		* @param int t_health
        * @return void
        */
	virtual void Health(int t_health) = 0;

	/**
        * @brief Pure virtual Index
        *
        * Pure virtual to be implemented by inherited
        *
		* @param int t_index
        * @return void
        */
	virtual void Index(int t_index) = 0;

	/**
        * @brief Pure virtual IsHostile
        *
        * Pure virtual to be implemented by inherited
        *
		* @param bool t_hostility
        * @return void
        */
	virtual void IsHostile(bool t_hostility) = 0;

	/**
        * @brief Pure virtual Staticity
        *
        * Pure virtual to be implemented by inherited
        *
		* @param bool t_staticity
        * @return void
        */
	virtual void Staticity(bool t_staticity) = 0;

	/**
        * @brief Virtual destructor
        *
        */
	virtual ~GameObject() {};
};

#endif