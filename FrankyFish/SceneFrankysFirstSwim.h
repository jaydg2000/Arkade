#pragma once
#include <ArkadeTypes.h>
#include <Scene.h>
#include <SpritePool.h>
#include <BoundingBoxCollisionDetector.h>
#include <RandomAnimator.h>
#include <Timer.h>
#include <Sound.h>
#include "Geometry.h"
#include "FrankySprite.h"
#include "FishGame.h"
#include "SceneRepository.h"
#include "MessageTypes.h"
#include "TileMap.h"
#include "TileSet.h"
#include "TileMapRepository.h"
#include "TileSetRepository.h"
#include "MultipleBoundingBoxCollisionDetector.h"

using namespace arkade;

#define SCENE_STATE_NOT_READY        0
#define SCENE_STATE_READY_PLAYER_ONE 1
#define SCENE_STATE_PLAYING          2
#define SCENE_STATE_GAME_OVER        3

#define FRANKY_START_Y               PLAYER_POSITION_Y
#define FRANKY_START_X               PLAYER_POSITION_X
#define WAVE_SPRITE_Y_POSITION       278
#define CAMERA_NORMAL_Y_POSITION     0
#define CAMERA_FOLLOW_THRESHOLD_TOP  450

#define CAMERA_SPEED                 8.0f
#define GROUND_SPEED				 6.75f

#define GROUND_START_X				 0.0f
#define GROUND_START_Y				 1344.0f
#define GROUND_SIZE_X				 1536.0f

class SceneFrankysFirstSwim :
	public Scene
{
public:
	SceneFrankysFirstSwim();
	~SceneFrankysFirstSwim();

protected:
	virtual void							on_setup();
	virtual void							on_begin();
	virtual void							on_check_input(InputManager* keyboard);
	virtual void							on_update();
	virtual void							on_render(Graphics* ptr_graphics);
	virtual void							on_end();
	virtual void							on_cleanup();
	virtual void							on_detect_collisions();
	virtual void							on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

private:
	Sound*									m_ptr_sound_coin_collected;
	Sound*									m_ptr_sound_splash;
	Sound*									m_ptr_sound_death;
	TileSet*								m_tile_set;
	TileMap*								m_map;
	Timer									m_swim_timer;
	Timer									m_splash_timer;
	CollisionDetector*						m_ptr_collision_detector;
	MultipleBoundingBoxCollisionDetector*	m_ptr_multibox_collision_detector;
	SceneRepository*						m_scene_repository;
	FrankySprite*							m_ptr_franky;
	Image*									m_ptr_background;
	Image*									m_ptr_ready;
	Image*									m_ptr_numbers;
	list<Sprite*>							m_gameitems;
	uint32_t								m_scene_state;
	uint32_t								m_score;
	bool									m_is_play_enabled;

	void									set_stage();
	bool									is_no_touch_happening(InputManager* ptr_keyboard);
	void									handle_player_ready_input(bool is_up_pressed);
	void									handle_playing_input(bool is_up_pressed);
	void									handle_game_over_input(bool is_up_pressed);
	void									end_game();
};

