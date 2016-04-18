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
	virtual Vector3 Transform() const = 0;
	virtual float TransformX() const = 0;
	virtual float TransformY() const = 0;
	virtual float TransformZ() const = 0;

	virtual Vector3 Rotation() const = 0;
	virtual float RotationX() const = 0;
	virtual float RotationY() const = 0;
	virtual float RotationZ() const = 0;

	virtual string ModelPath() const = 0;
	virtual string AIPath() const = 0;

	virtual int Health() const = 0;
	virtual int Index() const = 0;

	virtual bool IsHostile() const = 0;
	virtual bool Staticity() const = 0;

	///Setters
	virtual void Transform(Vector3 t_transform) = 0;
	virtual void TransformX(float t_transformX) = 0;
	virtual void TransformY(float t_transformY) = 0;
	virtual void TransformZ(float t_transformZ) = 0;

	virtual void Rotation(Vector3 t_rotation) = 0;
	virtual void RotationX(float t_rotationX) = 0;
	virtual void RotationY(float t_rotationY) = 0;
	virtual void RotationZ(float t_rotationZ) = 0;

	virtual void ModelPath(string t_modelPath) = 0;
	virtual void AIPath(string t_aiPath) = 0;

	virtual void Health(int t_health) = 0;
	virtual void Index(int t_index) = 0;

	virtual void IsHostile(bool t_hostility) = 0;
	virtual void Staticity(bool t_staticity) = 0;

	virtual ~GameObject() {};
};

#endif