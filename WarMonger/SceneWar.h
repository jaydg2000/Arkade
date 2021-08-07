#pragma once
#include <Scene.h>
#include <BoundingBoxCollisionDetector.h>
#include <Image.h>
#include <Button.h>
#include <Checkbox.h>
#include <Text.h>
#include "TiledMap.h"
#include <Font.h>
#include <Text.h>
#include <IntervalLogic.h>
#include "GameState.h"
#include <ArkadeTypes.h>
#include "UnitFactory.h"
#include "PathFinder.h"

using namespace arkade;

class SceneWar : public Scene 
{
public:
	SceneWar();
	~SceneWar();

	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_check_input(InputManager* ptr_keyboard);
	virtual void					on_update();
	virtual void					on_render(Graphics* ptr_graphics);
	virtual void					on_end();
	virtual void					on_cleanup();
	virtual void					on_detect_collisions();
	virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

private:
	GameState*						_state;
	TileSet*						_tileset;
	PathSolution*					_current_path_solution;
	Font*							_ptr_font;
	Font*							_ptr_font_unit_panel;
	Rect							_map_viewport;
	Rect							_map_preview_rect;
	Rect							_map_preview_focus_rect;
	uint32_t						_last_mouse_x, _last_mouse_y;
	UnitFactory*					_unit_factory;
	PathFinder*						_path_finder;
	Text*							_text_location;
	Text*							_text_map_count;
	bool							_should_render_current_unit;
	RGB*							_path_color;

	IntervalLogic*					_interval_flash_current_unit;
	IntervalLogic*					_interval_path_solution_color_swap;

	Form*							_form_unit_panel;
	Text*							_text_unit_name;
	Text*							_text_unit_health;	
	Button*							_button_move;
	Button*							_button_attack;
	Button*							_button_skip;
	Button*							_button_end_turn;
	Button*							_button_quit;
	Checkbox*						_checkbox_dig_in;

	void							_initialize_new_game();
	void							_display_preview(Graphics* graphics);
	void							_move_map_view_to_position();
	void							_hilite_map_cell(Graphics* graphics, uint32_t mouse_x, uint32_t mouse_y);
	void							_display_selected_map_location(Graphics* graphics, uint32_t map_x, uint32_t map_y);	
	void							_render_unit(Unit* unit, Graphics* graphics);
	void							_render_path_solution(Graphics* graphics);
	void							_render_panel(Graphics* graphics);
	void							_get_path_solution();
	void							_move_camera_to_unit();
	uint32_t						_top_left_x();
	uint32_t						_top_left_y();
	bool							_is_point_within_map_preview(uint32_t screen_x, uint32_t screen_y);
	bool							_is_point_within_map(uint32_t screen_x, uint32_t screen_y);
	void							_assign_movement_path_to_unit();
	void							_load_current_unit_info();
};

