#include "StaticAnimator.h"

namespace arkade {

	StaticAnimator::StaticAnimator(uint32_t number_of_frames)
		:Animator(number_of_frames, 0, false) {

		current_frame(0);
	}


	StaticAnimator::~StaticAnimator() {
	}

	void StaticAnimator::on_animate() {
		// This animator does nothing on_animate().
	}
}