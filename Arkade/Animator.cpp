#include "Animator.h"

namespace arkade {

	Animator::Animator(uint32_t number_of_frames, uint32_t delay_millis, bool started)
	{
		m_current_frame = 0;
		m_number_of_frames = number_of_frames;
		m_delay_millis = delay_millis;
		m_started = started;
		m_is_done = false;

		if (started)
			start();
	}


	Animator::~Animator(void)
	{
	}

	void Animator::start() {
		m_timer.delay(m_delay_millis);
		m_started = true;
		m_timer.start_or_resume();
	}

	void Animator::stop(bool reset_frame) {
		m_started = false;
		m_timer.pause();
		if(reset_frame)
			on_reset();
	}

	bool Animator::is_done() {
		return m_is_done;
	}

	void Animator::on_reset() {
		m_current_frame = 0;
	}

	uint32_t Animator::animate() {
		if(m_started && m_timer.has_elapsed())
			on_animate();
		
		return m_current_frame;
	}

	uint32_t Animator::current_frame() {
		return m_current_frame;
	}

	void Animator::current_frame(uint32_t frame_number) {
		m_current_frame = frame_number;
	}
}