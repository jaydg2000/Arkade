#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

namespace arkade {

	class MathUtil {
	public:
		MathUtil();
		~MathUtil();

		static float measure_distance(float x1, float y1, float x2, float y2);
		static float calculate_heading(float originX, float originY, float destX, float destY);
		static float degrees_to_radians(float angleDegrees) { return (float)(angleDegrees * M_PI / 180.0); }
		static float radians_to_degrees(float angleRadians) { return (float)(angleRadians * 180.0 / M_PI); }
	};

}