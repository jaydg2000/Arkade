#include "SceneMapEditor.h"
#include "MapLoader.h"

#define EDITOR_FORM_X 1516
#define EDITOR_FORM_Y 7
#define MAP_VIEW_OFFSET_X 5
#define MAP_VIEW_OFFSET_Y 5

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
}

SceneMapEditor::~SceneMapEditor()
{
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
	_editor_form = new Form(EDITOR_FORM_X, EDITOR_FORM_Y, make_size(400, 1053));
	
	_button_save = new Button("Save", _font, EDITOR_FORM_X + 190, EDITOR_FORM_Y + 900);
	_editor_form->add_control(_button_save);
	_button_save->border_margin({100,10});
	_button_save->border_color(RGB::White);
	_button_save->on_click([this]() {
		// todo: save map
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

	register_form(_editor_form);
}

void SceneMapEditor::on_begin()
{
	_editor_form->enable();
	_editor_form->show();
}

void SceneMapEditor::on_check_input(InputManager* input)
{
	_last_mouse_x = input->mouse_x();
	_last_mouse_y = input->mouse_y();
	
	if (input->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT))
	{
		_place_tile(_last_mouse_x, _last_mouse_y);
	}
}

void SceneMapEditor::on_update()
{
}

void SceneMapEditor::on_render(Graphics* ptr_graphics)
{
	_map->render(ptr_graphics, _map_viewport);
	_hilite_map_cell(ptr_graphics, _last_mouse_x, _last_mouse_y);
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
	_button_land = new Button(_image_land, EDITOR_FORM_X + 300, EDITOR_FORM_Y + 20);
	_button_land->border_margin({ 1,1 });	
	_editor_form->add_control(_button_land);
	_button_land->on_click([this]() {_select_brush(TILE_LAND_1);});

	_image_forest = new Image("res/tile_forest.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_forest = new Button(_image_forest, EDITOR_FORM_X + 300, EDITOR_FORM_Y + 60);
	_button_forest->border_margin({ 1,1 });	
	_editor_form->add_control(_button_forest);	
	_button_forest->on_click([this]() {_select_brush(TILE_FOREST_1); });

	_image_mountain = new Image("res/tile_mountain.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_mountain = new Button(_image_mountain, EDITOR_FORM_X + 300, EDITOR_FORM_Y + 100);
	_button_mountain->border_margin({ 1,1 });	
	_editor_form->add_control(_button_mountain);
	_button_mountain->on_click([this]() {_select_brush(TILE_MOUNTAIN_1); });

	_image_water = new Image("res/tile_water.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_water = new Button(_image_water, EDITOR_FORM_X + 300, EDITOR_FORM_Y + 140);
	_button_water->border_margin({ 1,1 });	
	_editor_form->add_control(_button_water);
	_button_water->on_click([this]() {_select_brush(TILE_WATER_1); });


	_image_river = new Image("res/tile_river.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_river = new Button(_image_river, EDITOR_FORM_X + 300, EDITOR_FORM_Y + 180);
	_button_river->border_margin({ 1,1 });	
	_editor_form->add_control(_button_river);
	_button_river->on_click([this]() {_select_brush(TILE_RIVER_1); });

	_image_city = new Image("res/tile_city.png", make_size(TILE_WIDTH, TILE_HEIGHT));
	_button_city = new Button(_image_city, EDITOR_FORM_X + 300, EDITOR_FORM_Y + 220);
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

