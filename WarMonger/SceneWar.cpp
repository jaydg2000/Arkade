#include "SceneWar.h"
#include "WarMonger_Main.h"
#include "MapLoader.h"

//#include <Random.h>
//#include <MathUtil.h>

SceneWar::SceneWar()
{
	_commandCenterImage = nullptr;
	_ptr_map = nullptr;
	_ptr_font = nullptr;
	_ptr_text = nullptr;
}

SceneWar::~SceneWar()
{
	delete _commandCenterImage;
	delete _ptr_map;
	delete _ptr_font;
}

void SceneWar::on_setup()
{
	this->_commandCenterImage = new Image(
		"res/background_command.png", 
		make_size(COMMAND_COMPONENT_WIDTH, COMMAND_COMPONENT_HEIGHT));

	//_ptr_map = new TiledMap();	
	//uint16_t tile_id = 101;
	//for (int row = 0; row < MAP_HEIGHT; row++)
	//{
	//	tile_id = tile_id == 101 ? 111 : 101;

	//	for (int col = 0; col < MAP_WIDTH; col++)
	//	{
	//		_ptr_map->tile_at(col, row, tile_id);
	//	}
	//}
	MapLoader loader;
	//loader.save_map("maps/test.bin", _ptr_map);
	_ptr_map = loader.load_map("maps/test.bin");

	_ptr_font = new Font("fonts/bahnschrift.ttf", 30);
	_ptr_text = new Text("This is my Text object!", _ptr_font);

	_interval = new IntervalLogic(100, 1, true);
	return;

}

void SceneWar::on_begin()
{
	_rotation = 0;
	_interval->start();
}

void SceneWar::on_check_input(InputManager* ptr_inputManager)
{
	ptr_inputManager->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT);
	if (ptr_inputManager->is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		stop();
	}
	if (ptr_inputManager->is_key_pressed(SDL_SCANCODE_A))
	{
		if (_interval->paused())
			_interval->start();
		else
			_interval->pause();
	}
}

void SceneWar::on_update()
{
	_interval->tick([this] (uint32_t step) {
		this->_rotation += 5;
		if (this->_rotation > 359)
			this->_rotation = 0;
	});
}

void SceneWar::on_render(Graphics* ptr_graphics)
{
	ptr_graphics->render(_commandCenterImage);

	ptr_graphics->render(_ptr_text, 200, 500, _rotation);
}

void SceneWar::on_end()
{
}

void SceneWar::on_cleanup()
{
}

void SceneWar::on_detect_collisions()
{
}

void SceneWar::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data)
{
}
