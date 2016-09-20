#pragma once
#include <SDL.h>

namespace arkade {

	class Random {
	public:
		Random();
		~Random();

		static void			seed();
		static int32_t		rand_int(int32_t low, int32_t high);
		static float		rand_float(float low, float high);
	};

}