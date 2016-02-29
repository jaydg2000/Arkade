#include "Timer.h"

namespace arkade {

	Timer::Timer(uint32_t delay_millis) {
		m_delay_millis = delay_millis;
		m_is_started = false;
		m_has_ever_been_started = false;
		m_pause_difference = 0;
	}
	
	Timer::~Timer(void) {
	}

	uint32_t Timer::delay(uint32_t delay_millis) {
		uint32_t old_delay = m_delay_millis;
		m_delay_millis = delay_millis;
		return old_delay;
	}

	void Timer::start() {
		m_is_started = true;
		m_has_ever_been_started = true;
		m_last_check_time = SDL_GetTicks();
	}

	void Timer::start(uint32_t delay_millis) {
		m_delay_millis = delay_millis;
		start();
	}

	void Timer::start_or_resume() {
		if(m_has_ever_been_started)
			resume();
		else
			start();
	}

	void Timer::stop() {
		m_is_started = false;
	}

	bool Timer::has_elapsed() {
		if(!m_is_started)
			return false;

		uint32_t current_time = SDL_GetTicks();
		
		if((m_last_check_time + m_delay_millis)<current_time) {
			m_last_check_time = current_time;
			return true;
		}
		
		return false;
	}

	void Timer::pause() {
		// this just makes sure m_last_check_time is up to date.
		has_elapsed();
		m_is_started = false;		
		m_pause_difference = (m_last_check_time + m_delay_millis) - SDL_GetTicks();
	}

	void Timer::resume() {
		m_last_check_time = SDL_GetTicks() - m_pause_difference;
		m_is_started = true;
	}

	bool Timer::is_paused() {
		return (m_has_ever_been_started && !m_is_started);
	}
}