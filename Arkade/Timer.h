#pragma once
#include <SDL.h>

namespace arkade {

	class Timer
	{
	public:
		Timer(uint32_t delay_millis = 0);
		~Timer(void);
				
		void				start();
		void				start(uint32_t delay_millis);
		void				start_or_resume();
		void				stop();
		void				pause();
		void				resume();
		bool				has_elapsed();
		bool				is_paused();
		uint32_t			delay(uint32_t delay_millis);

	private:
		bool				m_has_ever_been_started;
		bool				m_is_started;
		uint32_t			m_delay_millis;
		uint32_t			m_last_check_time;
		uint32_t			m_pause_difference;
	};

}