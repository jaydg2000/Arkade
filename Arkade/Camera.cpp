#include "Camera.h"

namespace arkade {

	Camera::Camera()
	{
		m_x = m_y = 0;
	}


	Camera::~Camera()
	{
	}

	float Camera::position_x() {
		return m_x;
	}

	void Camera::position_x(float x) {
		m_x = x;
	}

	float Camera::position_y() {
		return m_y;
	}

	void Camera::position_y(float y) {
		m_y = y;
	}

	void Camera::position(float x, float y) {
		m_x = x;
		m_y = y;
	}

	void Camera::move_relative_x(float x) {
		m_x += x;
	}

	void Camera::move_relative_y(float y) {
		m_y += y;
	}

	void Camera::move_relative(float x, float y) {
		m_x += x;
		m_y += y;
	}
}