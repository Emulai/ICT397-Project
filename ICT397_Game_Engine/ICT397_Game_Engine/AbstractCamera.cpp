#include "AbstractCamera.h" 
#include <glm/gtx/euler_angles.hpp>
 
glm::vec3 ACamera::UP = glm::vec3(0,1,0);

ACamera::ACamera(void) 
{  
}


ACamera::~ACamera(void)
{
}

void ACamera::SetupProjection(const float fovy, const float t_aspRatio) {
	m_projectionMatrix = glm::perspective(fovy, t_aspRatio, 0.1f, 1000.0f); 
	fov = fovy;
	m_aspectRatio = t_aspRatio;
} 

const glm::mat4 ACamera::GetViewMatrix() const {
	return m_viewMatrix;
}

const glm::mat4 ACamera::GetProjectionMatrix() const {
	return m_projectionMatrix;
}

const glm::vec3 ACamera::GetPosition() const {
	return m_position;
}

void ACamera::SetPosition(const glm::vec3 p) {
	m_position = p;
}
 
glm::mat4 ACamera::GetMatrixUsingYawPitchRoll(const float yaw, const float pitch, const float roll) {
	 
	return glm::yawPitchRoll(yaw, pitch, roll);  
}

const float ACamera::GetFOV() const {
	return fov;
} 

const float ACamera::GetAspectRatio() const {
	return m_aspectRatio;
}
