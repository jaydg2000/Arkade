#include "BoundsChecker.h"



BoundsChecker::BoundsChecker(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
{
	m_x_lower_boundary = x1;
	m_y_lower_boundary = y1;
	m_x_upper_boundary = x2;
	m_y_upper_boundary = y2;
}


BoundsChecker::~BoundsChecker()
{
}

bool BoundsChecker::is_out_of_bounds(float x, float y) {
	return (x < m_x_lower_boundary
		|| x > m_x_upper_boundary
		|| y < m_y_lower_boundary
		|| y > m_y_upper_boundary);
}