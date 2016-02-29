#include "BackwardOnceAnimator.h"

namespace arkade {

	BackwardOnceAnimator::BackwardOnceAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started)
		: Animator(number_of_frames, delay_millis, started)
	{
		m_current_frame = number_of_frames - 1;
	}


	BackwardOnceAnimator::~BackwardOnceAnimator()
	{
	}

	void BackwardOnceAnimator::on_animate()
	{
		if (!m_is_done)
			if (--m_current_frame < 0) {
				m_current_frame = 0;
				m_is_done = true;
			}
	}

}