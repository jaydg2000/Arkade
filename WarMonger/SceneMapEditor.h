#pragma once
#include <Scene.h>
#include <MenuForm.h>
#include <Button.h>
#include <Checkbox.h>
#include <Font.h>
#include "WarMonger_Main.h"
#include "TiledMap.h"
#include "TileSet.h"

using namespace arkade;

class SceneMapEditor : public Scene
{
public:
	SceneMapEditor();
	~SceneMapEditor();

	void							open_map(const char* filename);

protected:
	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_check_input(InputManager* keyboard);
	virtual void					on_update();
	virtual void					on_render(Graphics* ptr_graphics);
	virtual void					on_end();
	virtual void					on_cleanup();
	virtual void					on_detect_collisions();
	virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

private:
	uint32_t						_last_mouse_x;
	uint32_t						_last_mouse_y;
	uint16_t						_city_count;
	TiledMap*						_map;
	TileSet*						_tileset;
	const char*						_filename;
	Rect							_map_viewport;
	Rect							_map_preview_rect;
	Rect							_map_preview_focus_rect;
	Form*							_editor_form;
	Font*							_font;
	Button*							_button_save;
	Button*							_button_back;
	Button*							_button_all_land;
	Button*							_button_all_water;
	Button*							_button_land;
	Button*							_button_forest;
	Button*							_button_mountain;
	Button*							_button_river;
	Button*							_button_water;
	Button*							_button_city;
	Text*							_text_location;
	Checkbox*						_checkbox_large_brush;

	Image*							_image_save;
	Image*							_image_back;
	Image*							_image_land;
	Image*							_image_forest;
	Image*							_image_mountain;
	Image*							_image_river;
	Image*							_image_water;
	Image*							_image_city;

	Tile*							_current_brush;

	void							_load_tile_buttons();
	void							_select_brush(uint16_t tile_id);
	void							_deselect_all_brushes();
	void							_hilite_map_cell(Graphics* graphics, uint32_t mouse_x, uint32_t mouse_y);
	void							_place_tile(uint32_t mouse_x, uint32_t mouse_y);
	void							_splat_tiles(uint32_t mouse_x, uint32_t mouse_y);
	void							_display_preview(Graphics* graphics);
	void							_move_map_view_to_position();
	void							_display_selected_map_location(Graphics* graphics, uint32_t map_x, uint32_t map_y);
};

