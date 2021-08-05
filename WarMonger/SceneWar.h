#pragma once
#include <Scene.h>
#include <BoundingBoxCollisionDetector.h>
#include <Image.h>
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
	Rect							_map_viewport;
	Rect							_map_preview_rect;
	Rect							_map_preview_focus_rect;
	uint32_t						_last_mouse_x, _last_mouse_y;
	UnitFactory*					_unit_factory;
	PathFinder*						_path_finder;
	Text*							_text_location;
	bool							_should_render_current_unit;

	IntervalLogic*					_interval_flash_current_unit;

	void							_initialize_new_game();
	void							_display_preview(Graphics* graphics);
	void							_move_map_view_to_position();
	void							_hilite_map_cell(Graphics* graphics, uint32_t mouse_x, uint32_t mouse_y);
	void							_display_selected_map_location(Graphics* graphics, uint32_t map_x, uint32_t map_y);	
	void							_render_unit(Unit* unit, Graphics* graphics);
	void							_render_path_solution(Graphics* graphics);
	void							_get_path_solution();
};

