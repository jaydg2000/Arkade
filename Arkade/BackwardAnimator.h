#pragma once
#include "Animator.h"

namespace arkade {

	class BackwardAnimator : public Animator {
	public:
		BackwardAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started = true);
		~BackwardAnimator();

		// Inherited via Animator
		virtual void on_animate() override;
	};

}