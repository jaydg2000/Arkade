#pragma once
#include "Animator.h"

namespace arkade {

	class ForwardOnceAnimator : public Animator {
	public:
		ForwardOnceAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started = true);
		~ForwardOnceAnimator();

		virtual void on_animate() override;
	};

}