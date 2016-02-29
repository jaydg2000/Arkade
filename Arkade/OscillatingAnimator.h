#pragma once
#include "Animator.h"

namespace arkade {

	class OscillatingAnimator : public Animator {
	public:
		OscillatingAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started = true);
		~OscillatingAnimator();

	protected:
		bool			m_is_moving_forward;

		// Inherited via Animator
		virtual void on_animate() override;
	};

}