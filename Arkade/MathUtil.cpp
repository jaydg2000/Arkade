#include "MathUtil.h"

namespace arkade {

	//const double pi = 3.1415926535897;

	MathUtil::MathUtil()
	{
	}


	MathUtil::~MathUtil()
	{
	}

	float MathUtil::measure_distance(float x1, float y1, float x2, float y2) {
		float a = x1 - x2;
		float b = y1 - y2;
		float distance = sqrt(a * a + b * b);
		return distance;
	}

	float MathUtil::calculate_heading(float originX, float originY, float destX, float destY) {
		float thetaRadians = atan2(destY - originY, destX - originX);
		float degrees = (float)((thetaRadians + M_PI) * 360.0f / (2.0 * M_PI));
		return degrees;
	}
}