#include "SceneMapEditor.h"
#include "MapLoader.h"
#include <Random.h>

#define EDITOR_FORM_X 1512
#define EDITOR_FORM_Y 7
#define MAP_VIEW_OFFSET_X 5
#define MAP_VIEW_OFFSET_Y 5
#define TILE_BUTTONS_FIRST_ROW_Y 400
#define LARGE_BRUSH_REACH 5
#define LARGE_BRUSH_THICKNESS 25

SceneMapEditor::SceneMapEditor()
{
	_map = nullptr;
	_map_viewport.x = 5;
	_map_viewport.y = 5;
	_map_viewport.w = 1534;
	_map_viewport.h = 1056;
	_tileset = new TileSet();
	_last_mouse_x = _last_mouse_y = 0;
	_current_brush = nullptr;

	_map_preview_rect.x = EDITOR_FORM_X;
	_map_preview_rect.y = EDITOR_FORM_Y;
	_map_preview_rect.w = 402;
	_map_preview_rect.h = 402;

	_map_preview_focus_rect.w = 96;
	_map_preview_focus_rect.h = 66;
}

SceneMapEditor::~SceneMapEditor()
{
	// todo:  lots of cleaning up of pointers/SDL textures.
	if (_map)
		delete _map;
}

void SceneMapEditor::open_map(const char* filename)
{
	_filename = filename;
	MapLoader loader;
	_map = loader.load_map(filename);
}

void SceneMapEditor::on_setup()
{
	_font = new Font("fonts/bahnschrift.ttf", FORM_FONT_SIZE);
	_editor_form = new Form(EDITOR_FORM_X, EDITOR_FORM_Y, make_size(402, 1053));
	
	_button_save = new Button("Save", _font, EDITOR_FORM_X + 190, EDITOR_FORM_Y + 900);
	_editor_form->add_control(_button_save);
	_button_save->border_margin({100,10});
	_button_save->border_color(RGB::White);
	_button_save->on_click([this]() {
		MapLoader loader;
		loader.save_map(_filename, _map);
		stop();
	});

	_button_back = new Button("Back", _font, EDITOR_FORM_X + 190, EDITOR_FORM_Y + 950);
	_editor_form->add_control(_button_back);
	_button_back->border_margin({ 100,10 });
	_button_back->border_color(RGB::White);
	_button_back->on_click([this]() {
		stop();
	});

	_button_all_land = new Button("Set all to land", _font, EDITOR_FORM_X + 160, EDITOR_FORM_Y + 650);
	_editor_form->add_control(_button_all_land);
	_button_all_land->border_margin({ 70,10 });
	_button_all_land->border_color(RGB::White);
	_button_all_land->on_click([this]() {
		_map->fill(_tileset->tile(TILE_LAND_1));
	});

	_button_all_water = new Button("Set all to water", _font, EDITOR_FORM_X + 154, EDITOR_FORM_Y + 700);
	_editor_form->add_control(_button_all_water);
	_button_all_water->border_margin({ 64,10 });
	_button_all_water->border_color(RGB::White);
	_button_all_water->on_click([this]() {
		_map->fill(_tileset->tile(TILE_WATER_1));
	});

	_load_tile_buttons();

	_checkbox_large_brush = new Checkbox("Large brush", _font, EDITOR_FORM_X + 160, EDITOR_FORM_Y + 598);
	_editor_form->add_control(_checkbox_large_brush);

	register_form(_editor_form);

	_text_location = new Text("", _font);

	_map->grid(true);
}

void SceneMapEditor::on_begin()
{
	_editor_form->enable();
	_editor_form->show();

	_select_brush(TILE_LAND_1);
}

void SceneMapEditor::on_check_input(InputManager* input)
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

		// now handle mouse clicks on map
		if (_last_mouse_x < _map_viewport.x || _last_mouse_x > _map_viewport.x + _map_viewport.w)
			return;
		if (_checkbox_large_brush->checked())
		{
			_splat_tiles(_last_mouse_x, _last_mouse_y);
		}
		else
		{
			_place_tile(_last_mouse_x, _last_mouse_y);
		}
	}
}

void SceneMapEditor::on_update()
{
}

void SceneMapEditor::on_render(Graphics* ptr_graphics)
{
	_map->render(ptr_graphics, _map_viewport);
	_hilite_map_cell(ptr_graphics, _last_mouse_x, _last_mouse_y);
	_display_preview(ptr_graphics);
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

void SceneMapEditor::_load_tile_buttons()
{
	_image_land = new Image("res/tile_land.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_land = new Button(_image_land, EDITOR_FORM_X + 100, TILE_BUTTONS_FIRST_ROW_Y + 80);
	_button_land->border_margin({ 1,1 });	
	_editor_form->add_control(_button_land);
	_button_land->on_click([this]() {_select_brush(TILE_LAND_1);});

	_image_forest = new Image("res/tile_forest.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_forest = new Button(_image_forest, EDITOR_FORM_X + 300, TILE_BUTTONS_FIRST_ROW_Y + 80);
	_button_forest->border_margin({ 1,1 });	
	_editor_form->add_control(_button_forest);	
	_button_forest->on_click([this]() {_select_brush(TILE_FOREST_1); });

	_image_mountain = new Image("res/tile_mountain.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_mountain = new Button(_image_mountain, EDITOR_FORM_X + 100, TILE_BUTTONS_FIRST_ROW_Y + 120);
	_button_mountain->border_margin({ 1,1 });	
	_editor_form->add_control(_button_mountain);
	_button_mountain->on_click([this]() {_select_brush(TILE_MOUNTAIN_1); });

	_image_water = new Image("res/tile_water.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_water = new Button(_image_water, EDITOR_FORM_X + 300, TILE_BUTTONS_FIRST_ROW_Y + 120);
	_button_water->border_margin({ 1,1 });	
	_editor_form->add_control(_button_water);
	_button_water->on_click([this]() {_select_brush(TILE_WATER_1); });


	_image_river = new Image("res/tile_river.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_river = new Button(_image_river, EDITOR_FORM_X + 100, TILE_BUTTONS_FIRST_ROW_Y + 160);
	_button_river->border_margin({ 1,1 });	
	_editor_form->add_control(_button_river);
	_button_river->on_click([this]() {_select_brush(TILE_RIVER_1); });

	_image_city = new Image("res/tile_city.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_city = new Button(_image_city, EDITOR_FORM_X + 300, TILE_BUTTONS_FIRST_ROW_Y + 160);
	_button_city->border_margin({ 1,1 });	
	_editor_form->add_control(_button_city);
	_button_city->on_click([this]() {_select_brush(TILE_CITY_1); });

	_deselect_all_brushes();
}

void SceneMapEditor::_select_brush(uint16_t tile_id)
{
	_deselect_all_brushes();

	switch (tile_id)
	{
		case TILE_LAND_1:
			_current_brush = _tileset->tile(TILE_LAND_1);
			_button_land->border_color(RGB::White);
			break;
		case TILE_FOREST_1:
			_current_brush = _tileset->tile(TILE_FOREST_1);
			_button_forest->border_color(RGB::White);
			break;
		case TILE_MOUNTAIN_1:
			_current_brush = _tileset->tile(TILE_MOUNTAIN_1);
			_button_mountain->border_color(RGB::White);
			break;
		case TILE_RIVER_1:
			_current_brush = _tileset->tile(TILE_RIVER_1);
			_button_river->border_color(RGB::White);
			break;
		case TILE_WATER_1:
			_current_brush = _tileset->tile(TILE_WATER_1);
			_button_water->border_color(RGB::White);
			break;
		case TILE_CITY_1:
			_current_brush = _tileset->tile(TILE_CITY_1);
			_button_city->border_color(RGB::White);
			break;

	}
}

void SceneMapEditor::_deselect_all_brushes()
{
	_button_land->border_color(RGB::Black);
	_button_forest->border_color(RGB::Black);
	_button_mountain->border_color(RGB::Black);
	_button_water->border_color(RGB::Black);
	_button_river->border_color(RGB::Black);
	_button_city->border_color(RGB::Black);
}

void SceneMapEditor::_hilite_map_cell(Graphics* graphics, uint32_t mouse_x, uint32_t mouse_y)
{	
	uint32_t map_x = _map->screen_to_map_x(mouse_x);
	uint32_t map_y = _map->screen_to_map_y(mouse_y);

	if (map_x >= MAP_WIDTH || map_x < 0) 
		return;
	if (map_y >= MAP_HEIGHT || map_y < 0)
		return;

	Rect rect;
	rect.x = _map->map_to_screen_x(map_x) + MAP_VIEW_OFFSET_X;
	rect.y = _map->map_to_screen_y(map_y) + MAP_VIEW_OFFSET_Y;
	rect.w = TILE_WIDTH;
	rect.h = TILE_HEIGHT;

	if (rect.x > _map_viewport.x + (_map_viewport.w-TILE_WIDTH))
		return;
	if (rect.y > _map_viewport.y + (_map_viewport.h-TILE_HEIGHT))
		return;

	graphics->render(&rect);
	_display_selected_map_location(graphics, map_x, map_y);
}

void SceneMapEditor::_place_tile(uint32_t mouse_x, uint32_t mouse_y)
{
	if (!_current_brush)
		return;

	uint32_t map_x = _map->screen_to_map_x(mouse_x);
	uint32_t map_y = _map->screen_to_map_y(mouse_y);

	if (map_x >= MAP_WIDTH || map_x < 0)
		return;
	if (map_y >= MAP_HEIGHT || map_y < 0)
		return;

	_map->tile_at(map_x, map_y, _current_brush->tile_type());
}

void SceneMapEditor::_splat_tiles(uint32_t mouse_x, uint32_t mouse_y)
{
	_place_tile(mouse_x, mouse_y);
	for (int count = 0; count < LARGE_BRUSH_THICKNESS; count++)
	{
		int rand_x = Random::rand_int(0-LARGE_BRUSH_REACH, LARGE_BRUSH_REACH);
		int rand_y = Random::rand_int(0-LARGE_BRUSH_REACH, LARGE_BRUSH_REACH);
		_place_tile(mouse_x + (rand_x*TILE_WIDTH), mouse_y+(rand_y*TILE_HEIGHT));
	}
}

void SceneMapEditor::_display_preview(Graphics* graphics)
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
			uint16_t tile_id = _map->tile_at(x,y);
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
			pixels[1] = { px+1,py };
			pixels[2] = { px,py+1 };
			pixels[3] = { px+1,py+1 };
			graphics->render(pixels, 4, pixel_color);
		}
	}
	graphics->render(&_map_preview_focus_rect, RGB::Yellow);
}

void SceneMapEditor::_move_map_view_to_position()
{
	int32_t clicked_map_x = (_last_mouse_x - _map_preview_rect.x) / 2;
	int32_t clicked_map_y = (_last_mouse_y - _map_preview_rect.y) / 2;

	int32_t goto_map_x = clicked_map_x - (MAP_COMPONENT_DISPLAY_X / 2);
	int32_t goto_map_y = clicked_map_y - (MAP_COMPONENT_DISPLAY_Y / 2);

	if (goto_map_x < 0)
		goto_map_x = 0;
	if (goto_map_x >= (MAP_WIDTH - (MAP_COMPONENT_DISPLAY_X)) )
		goto_map_x = (MAP_WIDTH - (MAP_COMPONENT_DISPLAY_X));
	if (goto_map_y < 0)
		goto_map_y = 0;
	if (goto_map_y >= (MAP_HEIGHT - (MAP_COMPONENT_DISPLAY_Y)) )
		goto_map_y = (MAP_HEIGHT - (MAP_COMPONENT_DISPLAY_Y));

	Camera::instance()->position(goto_map_x*TILE_WIDTH, goto_map_y*TILE_HEIGHT);
}

void SceneMapEditor::_display_selected_map_location(Graphics* graphics, uint32_t map_x, uint32_t map_y)
{
	std::string location_str = "X:";
	location_str.append(std::to_string(map_x));
	location_str.append("  Y:");
	location_str.append(std::to_string(map_y));
	_text_location->text(location_str.c_str());
	graphics->render(_text_location, EDITOR_FORM_X + 10, 1030);
}

