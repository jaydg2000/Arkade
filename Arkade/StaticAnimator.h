#pragma once

#include "Animator.h"

namespace arkade {

	class StaticAnimator : public Animator {
	public:
		StaticAnimator(uint32_t number_of_frames);
		~StaticAnimator();

	protected:
		virtual void on_animate() override;
	};

}