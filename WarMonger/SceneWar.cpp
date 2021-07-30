#include "SceneWar.h"
#include "WarMonger_Main.h"
#include "MapLoader.h"

#define EDITOR_FORM_X 1512
#define EDITOR_FORM_Y 7
#define MAP_VIEW_OFFSET_X 5
#define MAP_VIEW_OFFSET_Y 5

SceneWar::SceneWar()
{
	_state = new GameState();

	_map_viewport.x = 5;
	_map_viewport.y = 5;
	_map_viewport.w = 1534;
	_map_viewport.h = 1056;

	_map_preview_rect.x = EDITOR_FORM_X;
	_map_preview_rect.y = EDITOR_FORM_Y;
	_map_preview_rect.w = 402;
	_map_preview_rect.h = 402;

	_map_preview_focus_rect.w = 96;
	_map_preview_focus_rect.h = 66;

}

SceneWar::~SceneWar()
{
	delete _ptr_font;
}

void SceneWar::on_setup()
{
	_ptr_font = new Font("fonts/bahnschrift.ttf", 30);
	_text_location = new Text("", _ptr_font);
	MapLoader map_loader;
	// for now, hardcoding to map 1.
	TiledMap* map = map_loader.load_map("maps/map1.bin");
	_state->map(map);

	return;
}

void SceneWar::on_begin()
{
}

void SceneWar::on_check_input(InputManager* input)
{
	_last_mouse_x = input->mouse_x();
	_last_mouse_y = input->mouse_y();

	if (input->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT))
	{
		// first handle mouse clicks on map preview
		if (_last_mouse_x > _map_preview_rect.x && _last_mouse_x < (_map_preview_rect.x + _map_preview_rect.w))
		{
			if (_last_mouse_y > _map_preview_rect.y && _last_mouse_y < (_map_preview_rect.y + _map_preview_rect.h))
			{
				_move_map_view_to_position();
				return;
			}
		}
	}

	if (input->is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		stop();
	}
}

void SceneWar::on_update()
{
}

void SceneWar::on_render(Graphics* graphics)
{
	_state->map()->render(graphics, _map_viewport);
	_hilite_map_cell(graphics, _last_mouse_x, _last_mouse_y);
	_display_preview(graphics);	
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

void SceneWar::_display_preview(Graphics* graphics)
{
	Camera* camera = Camera::instance();
	SDL_Point pixels[4];
	uint32_t left_edge_of_preview = _map_preview_rect.x + 1;
	uint32_t top_edge_of_preview = _map_preview_rect.y + 1;
	graphics->render(&_map_preview_rect);

	uint32_t camera_x = camera->position_x();
	uint32_t camera_y = camera->position_y();
	uint16_t top_left_tile_x = (camera_x / TILE_WIDTH);
	uint16_t top_left_tile_y = (camera_y / TILE_HEIGHT);
	_map_preview_focus_rect.x = left_edge_of_preview + (top_left_tile_x * 2);
	_map_preview_focus_rect.y = top_edge_of_preview + (top_left_tile_y * 2);

	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			RGB pixel_color = RGB::Black;
			uint16_t tile_id = _state->map()->tile_at(x, y);
			switch (tile_id)
			{
			case TILE_LAND_1:
			case TILE_RIVER_1:
				pixel_color = RGB::DarkGreen;
				break;
			case TILE_WATER_1:
				pixel_color = RGB::Blue;
				break;
			case TILE_MOUNTAIN_1:
				pixel_color = RGB::LightGray;
				break;
			case TILE_FOREST_1:
				pixel_color = RGB::Green;
				break;
			case TILE_CITY_1:
				pixel_color = RGB::White;
				break;
			}

			int px = left_edge_of_preview + (x * 2);
			int py = top_edge_of_preview + (y * 2);
			pixels[0] = { px,py };
			pixels[1] = { px + 1,py };
			pixels[2] = { px,py + 1 };
			pixels[3] = { px + 1,py + 1 };
			graphics->render(pixels, 4, pixel_color);
		}
	}
	graphics->render(&_map_preview_focus_rect, RGB::Yellow);
}

void SceneWar::_move_map_view_to_position()
{
	int32_t clicked_map_x = (_last_mouse_x - _map_preview_rect.x) / 2;
	int32_t clicked_map_y = (_last_mouse_y - _map_preview_rect.y) / 2;

	int32_t goto_map_x = clicked_map_x - (MAP_COMPONENT_DISPLAY_X / 2);
	int32_t goto_map_y = clicked_map_y - (MAP_COMPONENT_DISPLAY_Y / 2);

	if (goto_map_x < 0)
		goto_map_x = 0;
	if (goto_map_x >= (MAP_WIDTH - (MAP_COMPONENT_DISPLAY_X)))
		goto_map_x = (MAP_WIDTH - (MAP_COMPONENT_DISPLAY_X));
	if (goto_map_y < 0)
		goto_map_y = 0;
	if (goto_map_y >= (MAP_HEIGHT - (MAP_COMPONENT_DISPLAY_Y)))
		goto_map_y = (MAP_HEIGHT - (MAP_COMPONENT_DISPLAY_Y));

	Camera::instance()->position(goto_map_x * TILE_WIDTH, goto_map_y * TILE_HEIGHT);
}

void SceneWar::_hilite_map_cell(Graphics* graphics, uint32_t mouse_x, uint32_t mouse_y)
{
	TiledMap* map = _state->map();
	uint32_t map_x = map->screen_to_map_x(mouse_x);
	uint32_t map_y = map->screen_to_map_y(mouse_y);

	if (map_x >= MAP_WIDTH || map_x < 0)
		return;
	if (map_y >= MAP_HEIGHT || map_y < 0)
		return;

	Rect rect;
	rect.x = map->map_to_screen_x(map_x) + MAP_VIEW_OFFSET_X;
	rect.y = map->map_to_screen_y(map_y) + MAP_VIEW_OFFSET_Y;
	rect.w = TILE_WIDTH;
	rect.h = TILE_HEIGHT;

	if (rect.x > _map_viewport.x + (_map_viewport.w - TILE_WIDTH))
		return;
	if (rect.y > _map_viewport.y + (_map_viewport.h - TILE_HEIGHT))
		return;

	graphics->render(&rect);
	_display_selected_map_location(graphics, map_x, map_y);
}

void SceneWar::_display_selected_map_location(Graphics* graphics, uint32_t map_x, uint32_t map_y)
{
	std::string location_str = "X:";
	location_str.append(std::to_string(map_x));
	location_str.append("  Y:");
	location_str.append(std::to_string(map_y));
	_text_location->text(location_str.c_str());
	graphics->render(_text_location, EDITOR_FORM_X + 10, 1030);
}
