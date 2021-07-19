#include "SceneMapEditor.h"
#include "MapLoader.h"

SceneMapEditor::SceneMapEditor()
{
	_ptr_map = nullptr;
	_map_viewport.x = 5;
	_map_viewport.y = 5;
	_map_viewport.w = 1534;
	_map_viewport.h = 1056;
}

SceneMapEditor::~SceneMapEditor()
{
	if (_ptr_map)
		delete _ptr_map;
}

void SceneMapEditor::open_map(const char* filename)
{
	_filename = filename;
	MapLoader loader;
	_ptr_map = loader.load_map(filename);
}

void SceneMapEditor::on_setup()
{
}

void SceneMapEditor::on_begin()
{
}

void SceneMapEditor::on_check_input(InputManager* keyboard)
{
}

void SceneMapEditor::on_update()
{
}

void SceneMapEditor::on_render(Graphics* ptr_graphics)
{
	_ptr_map->render(ptr_graphics, _map_viewport);
}

void SceneMapEditor::on_end()
{
}

void SceneMapEditor::on_cleanup()
{
}

void SceneMapEditor::on_detect_collisions()
{
}

void SceneMapEditor::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data)
{
}
