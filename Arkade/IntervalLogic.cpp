#include "IntervalLogic.h"

namespace arkade {

	arkade::IntervalLogic::IntervalLogic(uint32_t interval_millis, uint32_t number_of_steps, bool repeating)
	{
		_current_step = 0;
		_total_steps = number_of_steps;
		_is_repeating = repeating;
		_ptr_timer = new Timer(interval_millis);
	}

	arkade::IntervalLogic::~IntervalLogic()
	{
		delete _ptr_timer;
	}

	void arkade::IntervalLogic::tick(std::function<void(uint32_t)> f)
	{
		if (_ptr_timer->has_elapsed())
			f(_current_step);
	}

	void arkade::IntervalLogic::pause()
	{
		_ptr_timer->pause();
	}

	void arkade::IntervalLogic::stop()
	{
		_ptr_timer->stop();
	}

	void arkade::IntervalLogic::start()
	{
		_ptr_timer->start_or_resume();
	}

	uint32_t IntervalLogic::step()
	{
		return _current_step;
	}
	bool IntervalLogic::paused()
	{
		return _ptr_timer->is_paused();
	}
}