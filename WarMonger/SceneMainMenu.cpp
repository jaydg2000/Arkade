#include "SceneMainMenu.h"
#include <ArkadeTypes.h>
#include "WarMonger_Main.h"
#include "SceneChooseMap.h"
#include "SceneMapEditor.h"

SceneMainMenu::SceneMainMenu()
{
	_ptr_font_button = nullptr;
}

SceneMainMenu::~SceneMainMenu()
{
}

void SceneMainMenu::on_setup()
{
	show_mouse();
	_setup_main_menu();
}

void SceneMainMenu::on_begin()
{
	_ptr_menu->show();
	_ptr_menu->enable();
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

void SceneMainMenu::_setup_main_menu()
{
	_ptr_font_button = new Font("fonts/bahnschrift.ttf", 15);

	_ptr_menu = new MenuForm(make_size(RES_WIDTH, RES_HEIGHT), _ptr_font_button);
	_ptr_menu->add_menu_item("Play", [this]() {
		// todo: play a game.
	});
	_ptr_menu->add_menu_item("Map Editor", [this]() {
		SceneChooseMap map_chooser;
		map_chooser.run();
		if (map_chooser.result() != nullptr)
		{			
			const char* filename = (const char*)(map_chooser.result());
			SceneMapEditor editor;
			std::string str = "maps/";
			str.append(filename);
			editor.open_map(str.c_str());
			editor.run();
		}
	});
	_ptr_menu->add_menu_item("Quit", [this]() {
		stop();
	});

	register_form(_ptr_menu->form());
}
