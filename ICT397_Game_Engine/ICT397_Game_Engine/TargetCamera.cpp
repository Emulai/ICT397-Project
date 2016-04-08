#define _USE_MATH_DEFINES
#include <cmath>
#include "TargetCamera.h"


TCamera::TCamera(void)
{  
	m_right = glm::vec3(1, 0, 0);
	m_up = glm::vec3(0, 1, 0);
	m_look = glm::vec3(0, 0, -1);
	m_minRotateY = -60;
	m_maxRotateY = 60;
	m_minTargetDistance = 1;
	m_maxTargetDistance = 10;
}


TCamera::~TCamera(void)
{
}
 
void TCamera::Update() {
	 
	glm::mat4 R = glm::yawPitchRoll(glm::radians(m_yaw),glm::radians(m_pitch),0.0f);
	glm::vec3 T = glm::vec3(0, 0, m_camPosition);
	T = glm::vec3(R * glm::vec4(T, 0.0f));
	m_position = m_target + T;
	m_look = glm::normalize(m_target - m_position);
	m_up = glm::vec3(R*glm::vec4(UP,0.0f));
	m_right = glm::cross(m_look, m_up);
	m_viewMatrix = glm::lookAt(m_position, m_target, m_up); 
}

void TCamera::SetCameraTarget(const glm::vec3 t_tgt) {
	m_target = t_tgt; 
	m_camPosition = glm::distance(m_position, m_target);
	m_camPosition = max(m_minTargetDistance, min(m_camPosition, m_maxTargetDistance));
	m_viewMatrix = glm::lookAt(m_position, m_target, m_up);

	m_yaw = 0;
	m_pitch = 0;

	if(m_viewMatrix[0][0] < 0)
		m_yaw = glm::degrees((float)(M_PI - asinf(-m_viewMatrix[2][0])) );
	else
		m_yaw = glm::degrees(asinf(-m_viewMatrix[2][0]));

	m_pitch = glm::degrees(asinf(-m_viewMatrix[1][2]));  
}

const glm::vec3 TCamera::GetCameraTarget() const {
	return m_target;
} 

void TCamera::RotateCamera(const float t_yaw, const float t_pitch, const float t_roll) {
 	m_yaw += t_yaw;
	m_pitch += t_pitch;
 	m_pitch = min( max(m_pitch, m_minRotateY), m_maxRotateY);
	Update();
}
 
void TCamera::PanCamera(const float xMove, const float yMove) {
	glm::vec3 l_X = m_right * xMove;
	glm::vec3 l_Y = m_up * yMove;
	m_position += l_X + l_Y;
	m_target += l_X + l_Y;
	Update();
}
 
void TCamera::ZoomCamera(const float t_zoomIn) { 
	m_position += m_look * t_zoomIn;
	m_camPosition = glm::distance(m_position, m_target); 
	m_camPosition = max(m_minTargetDistance, min(m_camPosition, m_maxTargetDistance));
	Update();
}
 
void TCamera::MoveCamera(const float xMove, const float zMove) {
	glm::vec3 l_X = m_right * xMove;
	glm::vec3 l_Y = m_look * zMove;
	m_position += l_X + l_Y;
	m_target += l_X + l_Y;
	Update();
}