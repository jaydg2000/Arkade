#pragma once
#include <SDL.h>

class BoundsChecker {
public:
	BoundsChecker(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
	~BoundsChecker();

	bool							is_out_of_bounds(float x, float y);

private:
	int32_t							m_x_lower_boundary;
	int32_t							m_y_lower_boundary;
	int32_t							m_x_upper_boundary;
	int32_t							m_y_upper_boundary;
};

