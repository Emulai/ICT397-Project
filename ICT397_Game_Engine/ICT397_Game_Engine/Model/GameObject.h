#ifndef GameObject_H
#define GameObject_H

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
        * @brief Returns the transform Vector3
        *
        * This function returns the Vector3 for transform to the client program
        *
        * @return Vector3 - m_transform
        */
	Vector3 Transform() const;

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
        * @brief Returns the rotation Vector3
        *
        * This function returns the Vector3 for rotation to the client program
        *
        * @return Vector3 - m_rotation
        */
	Vector3 Rotation() const;

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
        * @brief Returns the model path
        *
        * This function returns the model path of the object to the client program
        *
        * @return string - m_modelPath
        */
	int ModelReference() const;

	////////
	//Mutators
	////////

	/**
        * @brief Sets the transform Vector3
        *
        * This function sets the Vector3 for transform of the GameObject to that supplied
        * by the client program
        *
        * @param Vector3 t_transform - transform Vector3
        * @return void
        */
	void Transform(Vector3 t_transform);

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
        * @brief Sets the rotation Vector3
        *
        * This function sets the Vector3 for rotation of the GameObject to that supplied
        * by the client program
        *
        * @param Vector3 t_rotation - rotation Vector3
        * @return void
        */
	void Rotation(Vector3 t_rotation);

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
        * @brief Sets the object model ref. no.
        *
        * This function sets the object model reference number of the GameObject to that supplied
        * by the client program
        *
        * @param int t_modelReference - object model reference number
        * @return void
        */
	void ModelReference(int t_modelReference);
	
private:

	Vector3	m_transform;
	Vector3	m_rotation;
	int		m_modelReference;

};

#endif