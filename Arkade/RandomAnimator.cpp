#include "RandomAnimator.h"
#include "Random.h"

namespace arkade {

	RandomAnimator::RandomAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started)
		: Animator(number_of_frames, delay_millis, started)
	{
	}


	RandomAnimator::~RandomAnimator()
	{
	}

	void arkade::RandomAnimator::on_animate()
	{
		current_frame(Random::rand_int(0, m_number_of_frames - 1));
	}

	void RandomAnimator::on_reset() {
		return;
	}
}