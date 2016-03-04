#pragma once
#include "Animator.h"

namespace arkade {

	class RandomAnimator :
		public Animator
	{
	public:
		RandomAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started = true);
		~RandomAnimator();

		virtual void on_animate() override;
		virtual void on_reset() override;
	};

}