#pragma once
#include "abstractcamera.h"

class FCamera :
	public ACamera
{
public:
	FCamera(void);
	~FCamera(void);

	void Update();
	void Rotate(const float t_y, const float t_p, const float t_r);
	void Walk(const float t_zMove);
	void Strafe(const float t_xMove);
	void Lift(const float t_yMove);
	 

protected:
	float m_fyaw, m_fpitch, m_froll;
	
	glm::vec3 m_translation;
};


