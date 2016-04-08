#pragma once
#include "abstractcamera.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/euler_angles.hpp>

using namespace std;
//

class TCamera :
	public ACamera
{
public:
	TCamera(void);
	~TCamera(void);

	void Update();
	void RotateCamera(const float t_yaw, const float t_pitch, const float t_roll);
	 
	void SetCameraTarget(const glm::vec3 tgt);
	const glm::vec3 GetCameraTarget() const;

	void PanCamera(const float t_xMove, const float t_yMove);
	void ZoomCamera(const float t_zoom );
	void MoveCamera(const float t_xMove, const float t_zMove);

protected:
	glm::vec3 m_target;  
	float m_yaw, m_pitch, m_roll;
	 
	float m_minRotateY, m_maxRotateY;
	float m_camPosition;
	float m_minTargetDistance, m_maxTargetDistance;

};

