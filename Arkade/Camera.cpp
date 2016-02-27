#include "Camera.h"

namespace arkade {

	Camera* Camera::m_ptr_instance = nullptr;

	Camera::Camera()
	{
		m_x = m_y = 0;
	}


	Camera::~Camera()
	{
	}

	Camera* Camera::instance() {
		if (!m_ptr_instance)
			m_ptr_instance = new Camera();
		return m_ptr_instance;
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

	int Camera::x_to_screen(float x)
	{
		return (int)(x - m_x);
	}

	int Camera::y_to_screen(float y)
	{
		return (int)(y - m_y);
	}

	void Camera::to_screen(Rect* rect, float x, float y) {
		rect->x = (int)(x - m_x);
		rect->y = (int)(y - m_y);
	}
}