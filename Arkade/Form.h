#pragma once
#include <vector>
#include "ArkadeTypes.h"
#include "Graphics.h"
#include "FormControl.h"
#include "InputManager.h"
#include "MessageSink.h"
#include "MessageBroadcaster.h"

namespace arkade {

	class Form : public MessageSink, MessageBroadcaster
	{
	public:
		Form(uint32_t screen_x, uint32_t screen_y, Size size);
		~Form();

		void							size(Size size);
		void							position(uint32_t screen_x, uint32_t screen_y);
		void							add_control(FormControl* control);
		FormControl*					find_control(uint32_t id);
		bool							enabled();
		void							enable();
		void							disable();
		bool							visible();
		void							show();
		void							hide();
		void							show_border(bool should_render_border);

		virtual void					on_check_input(InputManager* keyboard);
		virtual void					on_update();
		virtual void					on_render(Graphics* ptr_graphics);
		virtual void					on_deactivate();
		virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

	private:
		uint32_t						_next_control_id;
		vector<FormControl*>			_controls;
		uint32_t						_x, _y;
		Size							_size;
		bool							_enabled;
		bool							_visible;
		bool							_should_render_border;

		virtual void					setup_controls();

	};
}