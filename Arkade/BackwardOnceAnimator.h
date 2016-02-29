#pragma once
#include "Animator.h"

namespace arkade {

	class BackwardOnceAnimator : public Animator {
	public:
		BackwardOnceAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started = true);
		~BackwardOnceAnimator();

		// Inherited via Animator
		virtual void on_animate() override;
	};

}