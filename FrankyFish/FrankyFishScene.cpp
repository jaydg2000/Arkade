#include "stdafx.h"
#include "FrankyFishScene.h"


FrankyFishScene::FrankyFishScene() : Scene()
{
	m_camera_speed = 4.5f;
}


FrankyFishScene::~FrankyFishScene()
{
}

void FrankyFishScene::load_common_textures() {
	TextureCache* ptr_texture_cache = TextureCache::instance();
	ptr_texture_cache->push("res/sprites/sprite_bird3.png", RGB(0, 0, 0));
	ptr_texture_cache->push("res/sprites/sprite_franky_swim_right.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/ready.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/game_over.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/plant-1.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/plant-2.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/plant-3.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/plant-4.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/plant-5.png", RGB(255, 255, 255));
	//ptr_texture_cache->push("res/sprites/sprite_ground.png", RGB(255, 255, 255));
	//ptr_texture_cache->push("res/sprites/sprite_wave.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/numbers.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/dollar.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/sprite_jelly.png", RGB(255, 255, 255));

	// load various images.
	m_ptr_background = new Image("res/sprites/gradient.png", make_size(720, 1280), 0.0f, 0.0f);
	m_ptr_ready = new Image("res/sprites/ready.png", make_size(363, 198), FRANKY_START_X + 50, FRANKY_START_Y - 125);
	m_ptr_game_over = new Image("res/sprites/game_over.png", make_size(415, 183), 290.0f, 500.0f);
	m_ptr_numbers = new Image("res/sprites/numbers.png", make_size(300, 48));

	m_ptr_background->use_screen_positioning(true);
}

void FrankyFishScene::load_common_sounds() {
	m_ptr_sound_coin_collected = new Sound("res/wav/coin10.wav");
	m_ptr_sound_splash = new Sound("res/wav/splash1.wav");
	m_ptr_sound_death = new Sound("res/wav/death.wav");
	m_ptr_back_track = new Sound("res/wav/jungle.wav");
}

void FrankyFishScene::load_dollar_spritepool() {
	for (int c = 0; c < 24; c++) {
		DollarSprite* dollar = new DollarSprite();
		m_dollar_pool.add(dollar);
	}
}

void FrankyFishScene::load_plant_spritepool() {
	m_plants.add(new Sprite("res/sprites/plant-1.png", make_size(269, 360)));
	m_plants.add(new Sprite("res/sprites/plant-1.png", make_size(269, 360)));

	m_plants.add(new Sprite("res/sprites/plant-2.png", make_size(269, 360)));
	m_plants.add(new Sprite("res/sprites/plant-2.png", make_size(269, 360)));

	m_plants.add(new Sprite("res/sprites/plant-3.png", make_size(192, 336)));
	m_plants.add(new Sprite("res/sprites/plant-3.png", make_size(192, 336)));

	m_plants.add(new Sprite("res/sprites/plant-4.png", make_size(192, 336)));
	m_plants.add(new Sprite("res/sprites/plant-4.png", make_size(192, 336)));

	m_plants.add(new Sprite("res/sprites/plant-5.png", make_size(153, 315)));
	m_plants.add(new Sprite("res/sprites/plant-5.png", make_size(153, 315)));

	//for (Sprite* sprite : *m_plants.get_sprite_list()) {
	//	sprite->scale(1.0f, 1.50f);
	//}
}

void FrankyFishScene::load_scene() {
	// load the tile set and tile map.
	TileSetRepository tile_set_repo;
	m_tile_set = tile_set_repo.load_tile_set();
	//TileMapRepository map_repo;
	//m_map = map_repo.load_map("res/scene/scene1.scn", m_tile_set);
	TileMapLoader map_repo;
	m_map = map_repo.load_map(m_tile_set);

	// tell each tile where it's positioned in the world.
	float tile_render_x;
	float tile_render_y;
	for (uint32_t tile_x = 0; tile_x < TILE_MAP_WIDTH; tile_x++) {
		for (uint32_t tile_y = 0; tile_y < TILE_MAP_HEIGHT; tile_y++) {
			Tile* tile = m_map->tile_at(tile_x, tile_y);
			if (tile != nullptr && tile->tile_type()) {
				tile_render_x = tile_x * TILE_WIDTH;
				tile_render_y = tile_y * TILE_HEIGHT;
				m_map->tile_at(tile_x, tile_y)->position(tile_render_x, tile_render_y);
			}
		}
	}
}

void FrankyFishScene::move_camera() {
	Camera* ptr_camera = Camera::instance();
	ptr_camera->move_relative_x(m_camera_speed);
	m_ptr_franky->move_relative_x(m_camera_speed);
	//m_ptr_background->x(m_ptr_background->x() + CAMERA_SPEED);
}

void FrankyFishScene::register_message_handling() {
	register_for_messages(MESSAGE_TYPE_DEAD);
	register_for_messages(MESSAGE_TYPE_SCORE);
	register_for_messages(MESSAGE_TYPE_REWARD_COLLECTED);
	register_for_messages(MESSAGE_TYPE_DOLLAR_COMPLETED);
}

void FrankyFishScene::set_stage() {

	// unregister any existing sprites from scene.
	for (Sprite* sprite : m_gameitems) {
		unregister_sprite(sprite);
	}

	// get the reloaded sprites.
	m_gameitems = m_scene_repository->load_gameitems();

	// register the sprites with the scene.
	for (Sprite* sprite : m_gameitems) {
		register_sprite(sprite);
	}

	m_dollar_pool.release_all();
}

bool FrankyFishScene::is_no_touch_happening(InputManager* ptr_input_manager) {
	return !ptr_input_manager->is_key_pressed(SDL_SCANCODE_UP);
}


void FrankyFishScene::add_plant() {
	if (Random::rand_int(0, 99) == 0) {
		Sprite* plant_sprite = m_plants.obtain();
		if (plant_sprite) {
			plant_sprite->position(1050 + Camera::instance()->position_x(), 846);
		}
	}
}

void FrankyFishScene::end_game() {
	if (m_is_music_enabled)
		m_ptr_back_track->stop_sound();
	m_is_play_enabled = false;
	m_scene_state = SCENE_STATE_GAME_OVER;
	Graphics::instance()->animation_on(false);
	disable_sprite_updates();
	if (m_is_sound_enabled)
		m_ptr_sound_death->play_sound();
}

void FrankyFishScene::handle_player_ready_input(bool is_up_pressed) {
	if (is_up_pressed) {
		m_scene_state = SCENE_STATE_PLAYING;
		enable_sprite_updates();
		Graphics::instance()->animation_on(true);
		if (m_is_music_enabled)
			m_ptr_back_track->play_sound(true);
		return;
	}
}

void FrankyFishScene::handle_playing_input(bool is_up_pressed) {

	if (is_up_pressed) {
		if (m_is_play_enabled) {
			m_ptr_franky->boost();
			//if(m_splash_timer.has_elapsed())
			//	m_ptr_sound_splash->play_sound();
			//m_splash_timer.start();
			m_is_play_enabled = false;
		}
		else {
			m_ptr_franky->rest();
		}
	}
	else {
		m_is_play_enabled = true;
		m_ptr_franky->rest();
	}
}

void FrankyFishScene::handle_game_over_input(bool is_up_pressed) {
	if (m_ptr_franky->can_restart()) {
		if (is_up_pressed) {
			m_scene_state = SCENE_STATE_READY_PLAYER_ONE;
			set_stage();
			on_begin();
			m_is_play_enabled = true;
			return;
		}
	}
}
