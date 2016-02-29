#include "ForwardOnceAnimator.h"

namespace arkade {

	ForwardOnceAnimator::ForwardOnceAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started)
		: Animator(number_of_frames, delay_millis, started)
	{
	}


	ForwardOnceAnimator::~ForwardOnceAnimator()
	{
	}

	void ForwardOnceAnimator::on_animate()
	{
		if (!m_is_done)
			if (++m_current_frame >= m_number_of_frames) {
				m_current_frame = m_number_of_frames - 1;
				m_is_done = true;
			}
	}
}