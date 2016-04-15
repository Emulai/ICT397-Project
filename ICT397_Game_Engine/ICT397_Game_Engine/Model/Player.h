#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player: public GameObject
{
public:
	///Getters
	virtual Vector3 Transform() const;
	virtual float TransformX() const;
	virtual float TransformY() const;
	virtual float TransformZ() const;

	virtual Vector3 Rotation() const;
	virtual float RotationX() const;
	virtual float RotationY() const;
	virtual float RotationZ() const;

	virtual string ModelPath() const;
	virtual string AIPath() const;

	virtual int Health() const;

	virtual bool IsHostile() const;
	virtual bool Staticity() const;

	///Setters
	virtual void Transform(Vector3 t_transform);
	virtual void TransformX(float t_transformX);
	virtual void TransformY(float t_transformY);
	virtual void TransformZ(float t_transformZ);

	virtual void Rotation(Vector3 t_rotation);
	virtual void RotationX(float t_rotationX);
	virtual void RotationY(float t_rotationY);
	virtual void RotationZ(float t_rotationZ);

	virtual void ModelPath(string t_modelPath);
	virtual void AIPath(string t_aiPath);

	virtual void Health(int t_health);

	virtual void IsHostile(bool t_hostility);
	virtual void Staticity(bool t_staticity);

	virtual ~Player() {};

private:
	
	Vector3 m_transform;
	Vector3 m_rotation;

	string m_modelPath;

	int m_health;

};

#endif