#pragma once
#include <SDL.h>
#include "Timer.h"

namespace arkade {

	class Animator
	{
	public:
		Animator(uint32_t number_of_frames, uint32_t delay_millis, bool started = true);
		~Animator(void);

		void					start();
		void					stop(bool reset_frame = false);
		uint32_t				animate();
		uint32_t				current_frame();
		void					current_frame(uint32_t frame_number);
	protected:
		virtual void			on_animate() = 0;
		virtual void			on_reset();

	private:
		bool					m_started;
		uint32_t				m_number_of_frames;
		uint32_t				m_delay_millis;
		uint32_t				m_current_frame;
		Timer					m_timer;
	};

}