#include "FreeCamera.h"


FCamera::FCamera()
{
	m_translation =glm::vec3(0);
}


FCamera::~FCamera(void)
{
}
 
void FCamera::Update() {
	glm::mat4 R = GetMatrixUsingYawPitchRoll(m_fyaw, m_fpitch, m_froll); 
	m_position += m_translation;
	m_translation = glm::vec3(0);

	m_look = glm::vec3(R*glm::vec4(0, 0, 1, 0));
	glm::vec3 l_tgt  = m_position + m_look;
	m_up = glm::vec3(R*glm::vec4(0, 1, 0, 0));
	m_right = glm::cross(m_look, m_up);
	m_viewMatrix = glm::lookAt(m_position, l_tgt, m_up);

	//normalize
	//look = glm::normalize(look);
	//up = glm::normalize(up);
	//right = glm::normalize(right);
}

void FCamera::Rotate(const float t_y, const float t_p, const float t_r) {
	m_fyaw = t_y;
	m_fpitch = t_p;
	m_froll = t_r;
}


void FCamera::Walk(const float t_zMove) {
	m_translation += (m_look * t_zMove);
}

void FCamera::Strafe(const float t_xMove) {
	m_translation += (m_right * t_xMove);
}

void FCamera::Lift(const float t_yMove) {
	m_translation += (m_up * t_yMove);
}