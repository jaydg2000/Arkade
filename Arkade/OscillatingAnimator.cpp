#include "OscillatingAnimator.h"

namespace arkade {

	OscillatingAnimator::OscillatingAnimator(uint32_t number_of_frames, uint32_t delay_millis, bool started)
		: Animator(number_of_frames, delay_millis, started)
	{
		m_is_moving_forward = true;
	}


	OscillatingAnimator::~OscillatingAnimator() {
	}

	void OscillatingAnimator::on_animate()
	{
		if (m_is_moving_forward) {

			if (m_current_frame < (m_number_of_frames - 1))
				m_current_frame++;
			else {
				m_is_moving_forward = false;
				m_current_frame--;
			}
		}
		else {
			if (m_current_frame > 0)
				m_current_frame--;
			else {
				m_is_moving_forward = true;
				m_current_frame++;
			}
		}
	}
}