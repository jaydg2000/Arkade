#pragma once
#include <functional>
#include "ArkadeTypes.h"
#include "InputManager.h"
#include "Graphics.h"
#include "MessageSink.h"
#include "MessageBroadcaster.h"
#include "IntervalLogic.h"

namespace arkade {

	class FormControl : public MessageSink, MessageBroadcaster
	{

	public:
		FormControl(uint32_t screen_x, uint32_t screen_y, Size size);
		~FormControl();

		uint32_t					id();
		uint32_t					x();
		uint32_t					y();
		void						position(uint32_t screen_x, uint32_t screen_y);
		Size						size();
		Size						border_margin();
		void						border_margin(Size border_margin);

		bool						is_point_on_control(uint32_t screen_x, uint32_t screen_y);
		void						set_id(uint32_t id);

		// user defined actions on the control.
		virtual void				on_click(std::function<void()> click_action);

		// internal lifecycle functions used by Form. Maybe make Form a friend?
		virtual void				on_setup();
		virtual void				on_check_input(InputManager* keyboard);
		virtual void				on_update();
		virtual void				on_cleanup() {};
		virtual void				on_render(Graphics* ptr_graphics) = 0;

	protected:
		virtual void				on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {};
		virtual void				on_mouse_down(uint32_t mouse_x, uint32_t mouse_y) {};
		virtual void				on_mouse_up() {};
		virtual void				on_mouse_over(uint32_t mouse_x, uint32_t mouse_y) {};

	private:
		uint32_t					_id;
		uint32_t					_x, _y;
		Size						_size;
		IntervalLogic*				_mouse_up_interval;
		Size						_margin;


		std::function<void()>		_click_action;

		void						click(uint32_t mouse_x, uint32_t mouse_y);
	};

}