#pragma once
#include <Scene.h>
#include <ArkadeTypes.h>
#include <Scene.h>
#include <SpritePool.h>
#include <BoundingBoxCollisionDetector.h>
#include <RandomAnimator.h>
#include <Timer.h>
#include <Sound.h>
#include <MessageSink.h>
#include "Geometry.h"
#include "FrankySprite.h"
#include "DollarSprite.h"
#include "FishGame.h"
#include "SceneRepository.h"
#include "MessageTypes.h"
#include "TileMap.h"
#include "TileSet.h"
#include "TileMapRepository.h"
#include "TileSetRepository.h"
#include "TileMapLoader.h"
#include "SceneLoader.h"
#include "MultipleBoundingBoxCollisionDetector.h"
#include "ScoreKeeper.h"

#define SCENE_TYPE_GAME              5
#define SCENE_STATE_NOT_READY        0
#define SCENE_STATE_READY_PLAYER_ONE 1
#define SCENE_STATE_PLAYING          2
#define SCENE_STATE_GAME_OVER        3
#define FRANKY_START_Y               PLAYER_POSITION_Y
#define FRANKY_START_X               PLAYER_POSITION_X
#define CAMERA_NORMAL_Y_POSITION     0

using namespace arkade;

class FrankyFishScene : public Scene
{
public:
	FrankyFishScene();
	~FrankyFishScene();

protected:
	bool									m_is_play_enabled;
	bool									m_is_sound_enabled;
	bool									m_is_music_enabled;
	list<Sprite*>							m_gameitems;
	uint32_t								m_scene_state;
	uint32_t								m_score;
	uint32_t								m_top_score;
	SpritePool								m_dollar_pool;
	SpritePool								m_plants;
	Sound*									m_ptr_back_track;
	Sound*									m_ptr_sound_coin_collected;
	Sound*									m_ptr_sound_splash;
	Sound*									m_ptr_sound_death;
	TileSet*								m_tile_set;
	TileMap*								m_map;
	//Timer									m_splash_timer;
	CollisionDetector*						m_ptr_collision_detector;
	MultipleBoundingBoxCollisionDetector*	m_ptr_multibox_collision_detector;
	SceneLoader*							m_scene_repository;
	ScoreKeeper*							m_score_keeper;
	FrankySprite*							m_ptr_franky;
	Image*									m_ptr_background;
	Image*									m_ptr_ready;
	Image*									m_ptr_game_over;
	Image*									m_ptr_top_score;
	Image*									m_ptr_numbers;
	float									m_camera_speed;
	
	void									load_common_textures();
	void									load_common_sounds();
	void									load_dollar_spritepool();
	void									load_plant_spritepool();
	virtual void							load_scene();
	virtual void							set_stage();

	void									move_camera();
	void									register_message_handling();
	bool									is_no_touch_happening(InputManager* ptr_keyboard);
	void									handle_player_ready_input(bool is_up_pressed);
	void									handle_playing_input(bool is_up_pressed);
	void									handle_game_over_input(bool is_up_pressed);
	void									add_plant();
	void									end_game();
	uint32_t								get_padding_for_number(uint32_t nbr);

};

