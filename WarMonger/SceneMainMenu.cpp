#include "SceneMainMenu.h"
#include <ArkadeTypes.h>

SceneMainMenu::SceneMainMenu()
{
	_ptr_font_button = nullptr;
	_ptr_button_play = nullptr;
}

SceneMainMenu::~SceneMainMenu()
{
}

void SceneMainMenu::on_setup()
{
	show_mouse();
	_ptr_font_button = new Font("fonts/bahnschrift.ttf", 15);
	_ptr_text_button_play = new Text("Play", _ptr_font_button);

	_ptr_button_play = new Button(_ptr_text_button_play, 950, 400);
	_ptr_button_play->border_color({255,255,255,255});
	_ptr_button_play->border_margin(make_size(50,10));
	
}

void SceneMainMenu::on_begin()
{
}

void SceneMainMenu::on_check_input(InputManager* ptr_inputManager)
{
	if (ptr_inputManager->is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		stop();
	}
}

void SceneMainMenu::on_update()
{
}

void SceneMainMenu::on_render(Graphics* ptr_graphics)
{
	ptr_graphics->render(_ptr_button_play);
}

void SceneMainMenu::on_end()
{
}

void SceneMainMenu::on_cleanup()
{
	hide_mouse();
}

void SceneMainMenu::on_detect_collisions()
{
}

void SceneMainMenu::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data)
{
}
