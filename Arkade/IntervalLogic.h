#pragma once
#include <functional>
#include "ArkadeTypes.h"
#include "Timer.h"


namespace arkade {
	class IntervalLogic
	{
	public:
		IntervalLogic(uint32_t interval_millis, uint32_t number_of_steps, bool repeating = true);
		~IntervalLogic();

		void					tick(std::function<void(uint32_t)> f);
		void					pause();
		void					stop();
		void					start();
		uint32_t				step();
		bool					paused();

	protected:

	private:
		uint32_t				_current_step;
		uint32_t				_total_steps;
		bool					_is_repeating;
		Timer*					_ptr_timer;
	};
}
