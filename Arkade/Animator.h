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
		bool					is_done();

	protected:
		int32_t					m_current_frame;
		bool					m_started;
		uint32_t				m_number_of_frames;
		uint32_t				m_delay_millis;
		Timer					m_timer;
		bool					m_is_done;

		virtual void			on_animate() = 0;
		virtual void			on_reset();
	};

}