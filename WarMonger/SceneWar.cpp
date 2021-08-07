#include "SceneWar.h"
#include "WarMonger_Main.h"
#include "MapLoader.h"
#include <Random.h>

#define EDITOR_FORM_X 1512
#define EDITOR_FORM_Y 7
#define MAP_VIEW_OFFSET_X 6
#define MAP_VIEW_OFFSET_Y 6
#define PANEL_Y 415

SceneWar::SceneWar()
{
	_state = new GameState();

	_map_viewport.x = MAP_VIEW_OFFSET_X;
	_map_viewport.y = MAP_VIEW_OFFSET_Y;
	_map_viewport.w = 1534;
	_map_viewport.h = 1056;

	_map_preview_rect.x = EDITOR_FORM_X;
	_map_preview_rect.y = EDITOR_FORM_Y;
	_map_preview_rect.w = 402;
	_map_preview_rect.h = 402;

	_map_preview_focus_rect.w = 96;
	_map_preview_focus_rect.h = 66;

	_interval_flash_current_unit = new IntervalLogic(250, 2);
	_interval_path_solution_color_swap = new IntervalLogic(100,3);
	_should_render_current_unit = true;
	_unit_factory = new UnitFactory();
	_path_finder = new PathFinder();
	_current_path_solution = new PathSolution();
}

SceneWar::~SceneWar()
{
	delete _ptr_font;
	delete _ptr_font_unit_panel;
	delete _state;
	delete _interval_flash_current_unit;
	delete _interval_path_solution_color_swap;
	delete _unit_factory;
	delete _path_finder;
}

void SceneWar::on_setup()
{
	UnitSpecification::init();
	_ptr_font = new Font("fonts/bahnschrift.ttf", 30);
	_ptr_font_unit_panel = new Font("fonts/bahnschrift.ttf", 21);
	_text_location = new Text("", _ptr_font);
	_text_map_count = new Text("", _ptr_font_unit_panel);
	_text_unit_name = new Text("", _ptr_font_unit_panel);
	_checkbox_dig_in = new Checkbox("Dig in", _ptr_font_unit_panel, 1800, PANEL_Y);

	//_form_unit_panel = new Form(1520, PANEL_Y, make_size(500,900));
	//_form_unit_panel->add_control(_checkbox_dig_in);

	MapLoader map_loader;
	// for now, hardcoding to map 1.
	TiledMap* map = map_loader.load_map("maps/map1.bin");
	_state->map(map);

	return;
}

void SceneWar::on_begin()
{
	Player* player1 = new Player();
	_state->add_player(player1);
	Unit* unit = _unit_factory->create_unit(UNIT_INFANTRY);
	unit->position(100,100);
	player1->add_unit(unit);
	unit = _unit_factory->create_unit(UNIT_MECHANIZED_INFANTRY);
	unit->position(102, 100);
	player1->add_unit(unit);

	_load_current_unit_info();

	_interval_flash_current_unit->start();
	_interval_path_solution_color_swap->start();
	_move_camera_to_unit();
	_state->mode(MODE_WAITING);

	//register_form(_form_unit_panel);
}

void SceneWar::on_check_input(InputManager* input)
{
	_last_mouse_x = input->mouse_x();
	_last_mouse_y = input->mouse_y();

	if (input->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT))
	{
		// first handle mouse clicks on map preview
		if (_is_point_within_map_preview(_last_mouse_x, _last_mouse_y))
		{
			_move_map_view_to_position();
			return;
		}
	}

	if (input->is_key_pressed(SDL_SCANCODE_ESCAPE))
	{
		stop();
	}
}

void SceneWar::on_update()
{
	Player* player = _state->current_player();
	Unit* unit = _state->current_unit();

	if (unit)
	{
		_get_path_solution();
	}
}

void SceneWar::on_render(Graphics* graphics)
{
	_state->map()->render(graphics, _map_viewport);
	_hilite_map_cell(graphics, _last_mouse_x, _last_mouse_y);
	_display_preview(graphics);

	Player* player = _state->current_player();
	Unit* current_unit = _state->current_unit();
	vector<Unit*>* all_units = player->units();

	Camera* camera = Camera::instance();
	// determine what portion of the map is visible.
	uint32_t camera_x = camera->position_x();
	uint32_t camera_y = camera->position_y();
	uint16_t top_left_tile_x = (camera_x / TILE_WIDTH);
	uint16_t top_left_tile_y = (camera_y / TILE_HEIGHT);
	uint16_t bottom_right_tile_x = top_left_tile_x + (_map_viewport.w / TILE_WIDTH) - 1;
	uint16_t bottom_right_tile_y = top_left_tile_y + (_map_viewport.h / TILE_HEIGHT) - 1;

	if (_state->mode() == MODE_MOVING)
	{
		_render_path_solution(graphics);
	}

	for (Unit* unit : *all_units)
	{
		if (unit != current_unit || _should_render_current_unit)
		{
			if (unit->x() < top_left_tile_x || unit->x() > bottom_right_tile_x)
				return;
			if (unit->y() < top_left_tile_y || unit->y() > bottom_right_tile_y)
				return;
			_render_unit(unit, graphics);
		}
	}

	_interval_flash_current_unit->tick([this](uint32_t step) {
		_should_render_current_unit = step;
	});

	if (_state->current_unit())
	{
		_render_panel(graphics);
	}
}

void SceneWar::_render_unit(Unit* unit, Graphics* graphics)
{
	uint32_t sprite_x = _state->map()->map_to_screen_x(unit->x()) + MAP_VIEW_OFFSET_X;
	uint32_t sprite_y = _state->map()->map_to_screen_y(unit->y()) + MAP_VIEW_OFFSET_Y;
	unit->sprite()->position(sprite_x, sprite_y);
	graphics->render(unit->sprite()->destination_rect(), unit->color(), true);
	graphics->render(unit->sprite());	
}

void SceneWar::_render_path_solution(Graphics* graphics)
{	
	//_interval_path_solution_color_swap->tick([this](uint32_t step) {
	//	switch (step)
	//	{
	//		case 0:
	//			this->_path_color = &RGB(0xD1, 0xD0, 0xCD);
	//			break;
	//		case 1:
	//			this->_path_color = &RGB(0x9C, 0x9B, 0x9A);
	//			break;
	//		case 2:
	//			this->_path_color = &RGB(0x7D, 0x7D, 0x7D);
	//			break;
	//	}
	//});

	if (!_current_path_solution || _current_path_solution->empty())
		return;

	TiledMap* map = _state->map();

	list<Point>* points = _current_path_solution->points();
	for (Point point : *points)
	{
		Rect rect;
		rect.x = map->map_to_screen_x(point.x) + MAP_VIEW_OFFSET_X;
		rect.y = map->map_to_screen_y(point.y) + MAP_VIEW_OFFSET_Y;
		rect.w = TILE_WIDTH;
		rect.h = TILE_HEIGHT;

		if (rect.x > _map_viewport.x + (_map_viewport.w - TILE_WIDTH))
			return;
		if (rect.y > _map_viewport.y + (_map_viewport.h - TILE_HEIGHT))
			return;

		graphics->render(&rect);
	}

	//uint32_t first_tile_x = _top_left_x();
	//uint32_t first_tile_y = _top_left_y();
	//for (int y = first_tile_y; y < first_tile_y + MAP_COMPONENT_DISPLAY_Y-1; y++)
	//{
	//	for (int x = first_tile_x; x < first_tile_x + MAP_COMPONENT_DISPLAY_X-1; x++)
	//	{
	//		uint32_t count = _path_finder->count_at(x,y);
	//						
	//		char buff[4];
	//		if (count > 999)
	//			_text_map_count->text("#");
	//		else
	//		{
	//			_itoa_s(count, buff, 10);
	//			_text_map_count->text(buff);
	//		}
	//		uint32_t sx = map->map_to_screen_x(x) + MAP_VIEW_OFFSET_X;
	//		uint32_t sy = map->map_to_screen_y(y) + MAP_VIEW_OFFSET_Y;
	//		graphics->render(_text_map_count, sx, sy);
	//	}
	//}

}

void SceneWar::_render_panel(Graphics* graphics)
{	
	Unit* unit = _state->current_unit();
	graphics->render(_text_unit_name, 1520, PANEL_Y);

	if (unit->category() == CATEGORY_LAND)
	{
		_checkbox_dig_in->on_render(graphics);
	}

}

void SceneWar::_load_current_unit_info()
{
	Unit* unit = _state->current_unit();
	_text_unit_name->text(unit->name());
}

void SceneWar::_move_camera_to_unit()
{
	Camera* camera = Camera::instance();
	uint32_t map_x = _state->current_unit()->x();
	uint32_t map_y = _state->current_unit()->y();
	uint32_t screen_x = _state->map()->map_to_screen_x(map_x) - (RES_WIDTH / 2);
	uint32_t screen_y = _state->map()->map_to_screen_y(map_y) - (RES_HEIGHT / 2);
	Camera::instance()->position(screen_x, screen_y);
}

uint32_t SceneWar::_top_left_x()
{
	return _state->map()->screen_to_map_x(16);
}

bool SceneWar::_is_point_within_map_preview(uint32_t screen_x, uint32_t screen_y)
{
	return (screen_x > _map_preview_rect.x && screen_x < (_map_preview_rect.x + _map_preview_rect.w)) &&
		   (screen_y > _map_preview_rect.y && screen_y < (_map_preview_rect.y + _map_preview_rect.h));
}

bool SceneWar::_is_point_within_map(uint32_t screen_x, uint32_t screen_y)
{
	return (screen_x >= _map_viewport.x && screen_x < _map_viewport.x + (_map_viewport.w-1)) &&
		   (screen_y >= _map_viewport.y && screen_y < _map_viewport.y + (_map_viewport.h-1));
}

uint32_t SceneWar::_top_left_y()
{
	return _state->map()->screen_to_map_y(16);
}

void SceneWar::on_end()
{
	_interval_flash_current_unit->start();
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

void SceneWar::_get_path_solution()
{		
	_current_path_solution->clear();
	TiledMap* map = _state->map();
	uint32_t map_x = map->screen_to_map_x(_last_mouse_x);
	uint32_t map_y = map->screen_to_map_y(_last_mouse_y);

	if (map_x >= MAP_WIDTH || map_x < 0)
		return;
	if (map_y >= MAP_HEIGHT || map_y < 0)
		return;

	Unit* unit = _state->current_unit();
	_current_path_solution = _path_finder->find_path(map, unit->x(), unit->y(), map_x, map_y, unit->terrain_costs());
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

void SceneWar::_initialize_new_game()
{
	vector<City*>* cities = _state->cities();
	uint32_t number_of_cities = cities->size();
	vector<Player*>* players = _state->players();
	
	for (Player* player : *players)
	{
		uint32_t city_index = Random::rand_int(0, number_of_cities - 1);
		// todo: make sure to not assign an already assigned city.
		player->take_city((*cities)[city_index]);
	}
	
}

void SceneWar::_assign_movement_path_to_unit()
{
	if (_current_path_solution && !_current_path_solution->empty())
	{
		Unit* unit = _state->current_unit();
		// order to unit to move/attack.
		while (!_current_path_solution->empty())
		{
			Point point = _current_path_solution->pop_point();
			unit->move(point);
		}
		_state->select_next_unit();
	}
}


