#pragma once
#include "Animator.h"

namespace arkade {

	class ForwardAnimator : public Animator {
	public:
		ForwardAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started = true);
		~ForwardAnimator();

		virtual void on_animate() override;
	};

}