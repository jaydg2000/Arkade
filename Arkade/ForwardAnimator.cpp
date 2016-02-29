#include "ForwardAnimator.h"

namespace arkade {

	ForwardAnimator::ForwardAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started) 
		: Animator(number_of_frames, delay_millis, started)
	{
	}


	ForwardAnimator::~ForwardAnimator()
	{
	}

	void arkade::ForwardAnimator::on_animate()
	{
		if (++m_current_frame >= m_number_of_frames)
			m_current_frame = 0;
	}

}