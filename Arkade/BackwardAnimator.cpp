#include "BackwardAnimator.h"

namespace arkade {

	BackwardAnimator::BackwardAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started)
		: Animator(number_of_frames, delay_millis, started)
	{
		m_current_frame = number_of_frames - 1;
	}


	BackwardAnimator::~BackwardAnimator()
	{
	}

	void BackwardAnimator::on_animate()
	{
		if (--m_current_frame < 0)
			m_current_frame = m_number_of_frames - 1;
	}
}