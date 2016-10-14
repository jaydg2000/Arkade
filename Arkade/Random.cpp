#include "Random.h"
#include <random>
#include <time.h>

namespace arkade {

	Random::Random()
	{
	}


	Random::~Random()
	{
	}

	void Random::seed() {
		srand((unsigned int)time(NULL));
	}

	int32_t Random::rand_int(int32_t min, int32_t max) {
		return rand() % (max - min) + min;
	}

	float Random::rand_float(float low, float high) {
		return low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low)));
	}

	bool Random::rand_bool() {
		return rand_int(0, 1) == 0;
	}
}