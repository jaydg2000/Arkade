#include "FrankyFishScene.h"


FrankyFishScene::FrankyFishScene() : Scene()
{
	type(SCENE_TYPE_GAME);
	m_ptr_collision_detector = new BoundingBoxCollisionDetector();
	m_ptr_multibox_collision_detector = new MultipleBoundingBoxCollisionDetector();
	m_is_sound_enabled = true;
	m_is_music_enabled = true;
	m_camera_speed = 4.5f;
	m_score_keeper = new ScoreKeeper();
	m_respawn_position.x = 0.0f;
	m_respawn_position.y = 0.0f;
}


FrankyFishScene::~FrankyFishScene()
{
	delete m_ptr_franky;
	delete m_ptr_background;
	delete m_scene_repository;
	delete m_ptr_collision_detector;
	delete m_ptr_multibox_collision_detector;
	delete m_score_keeper;
}

void FrankyFishScene::set_audio(bool is_sound_on, bool is_music_on) {
	m_is_sound_enabled = is_sound_on;
	m_is_music_enabled = is_music_on;
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
	ptr_texture_cache->push("res/sprites/numbers_water.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/little_coin.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/sprite_jelly.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/boulder.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/spike.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/heart.png", RGB(255, 255, 255));

	// load various images.
	m_ptr_background = new Image("res/sprites/gradient.png", make_size(720, 1280), 0.0f, 0.0f);
	m_ptr_ready = new Image("res/sprites/ready.png", make_size(363, 198), FRANKY_START_X + 50, FRANKY_START_Y - 125);
	m_ptr_game_over = new Image("res/sprites/game_over.png", make_size(415, 183), 290.0f, 200.0f);
	m_ptr_top_score = new Image("res/sprites/top_score.png", make_size(432, 232), 150.0f, 500.0f);
	m_ptr_numbers = new Image("res/sprites/numbers_water.png", make_size(370, 53));

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
}

void FrankyFishScene::load_scene() {
	// load the tile set and tile map.
	TileSetRepository tile_set_repo;
	m_tile_set = tile_set_repo.load_tile_set();
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

	m_top_score = m_score_keeper->read();
}

void FrankyFishScene::move_camera() {
	Camera* ptr_camera = Camera::instance();
	ptr_camera->move_relative_x(m_camera_speed);
	m_ptr_franky->move_relative_x(m_camera_speed);
	
	if (ptr_camera->position_x() >= 62592) {
		m_ptr_franky->position_x(FRANKY_START_X);
		ptr_camera->position(0, 0);
	}

}

void FrankyFishScene::register_message_handling() {
	register_for_messages(MESSAGE_TYPE_DEAD);
	register_for_messages(MESSAGE_TYPE_SCORE);
	register_for_messages(MESSAGE_TYPE_REWARD_COLLECTED);
	register_for_messages(MESSAGE_TYPE_DOLLAR_COMPLETED);
	register_for_messages(MESSAGE_TYPE_EXTRA_LIFE);
}

void FrankyFishScene::set_stage() {

	m_ptr_franky->position(FRANKY_START_X, FRANKY_START_Y);
	//m_ptr_franky->position(472*128, FRANKY_START_Y);

	// set camera at the start position.
	Camera::instance()->position(CAMERA_START_X_POSITION, CAMERA_START_Y_POSITION);
	//Camera::instance()->position(m_ptr_franky->position_x()-144, 0);

	for (Sprite* ptr_sprite : m_gameitems) {
		GameSprite* ptr_game_sprite = (GameSprite*)ptr_sprite;
		ptr_game_sprite->is_visible(true);
		ptr_game_sprite->on_set_stage();
	}
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

	if (m_score > m_top_score) {
		m_score_keeper->save(m_score);
		m_top_score = m_score;
	}
}

bool FrankyFishScene::has_extra_life() {
	return m_respawn_position.x > 0 && m_respawn_position.y > 0;
}

void FrankyFishScene::handle_player_ready_input(InputManager* ptr_keyboard, bool is_up_pressed) {
	if (ptr_keyboard->is_mouse_button_pressed()) {
		int mx = ptr_keyboard->mouse_x();
		int my = ptr_keyboard->mouse_y();

		if (m_ptr_play->is_clicked(mx, my)) {
			m_scene_state = SCENE_STATE_PLAYING;
			enable_sprite_updates();
			Graphics::instance()->animation_on(true);
			if (m_is_music_enabled)
				m_ptr_back_track->play_sound(true);
			return;
		}
	}
}

void FrankyFishScene::handle_playing_input(bool is_up_pressed) {

	if (is_up_pressed) {
		if (m_is_play_enabled) {
			m_ptr_franky->boost();
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

void FrankyFishScene::handle_game_over_input(InputManager* ptr_keyboard, bool is_up_pressed) {
	if (m_ptr_franky->can_restart()) {
		if (ptr_keyboard->is_mouse_button_pressed()) {
			int mx = ptr_keyboard->mouse_x();
			int my = ptr_keyboard->mouse_y();

			if (m_ptr_try_again->is_clicked(mx, my)) {
				m_scene_state = SCENE_STATE_READY_PLAYER_ONE;
				if (has_extra_life()) {
					on_respawn();
				}
				else {
					set_stage();
					on_begin();
				}
				m_is_play_enabled = true;
				return;
			}
		}
	}
}

uint32_t FrankyFishScene::get_padding_for_number(uint32_t nbr) {
	uint32_t digits = 0;

	if (nbr < 10)
		digits = 0;
	else if (nbr < 100)
		digits = 1;
	else if (nbr < 1000)
		digits = 2;
	else if (nbr < 10000)
		digits = 3;

	return digits * 30;
}

void FrankyFishScene::on_respawn() {
	m_ptr_franky->reset();
	m_ptr_franky->position(m_respawn_position.x, m_respawn_position.y);
	m_respawn_position.x = 0.0f;
	m_respawn_position.y = 0.0f;
	Camera::instance()->position(m_ptr_franky->position_x() - 144, 0);
	m_scene_state = SCENE_STATE_READY_PLAYER_ONE;
	m_ptr_ready->x(FRANKY_START_X + 50.0f);
	m_ptr_ready->y(FRANKY_START_Y - 125.0f);	
	disable_sprite_updates();
	Graphics::instance()->animation_on(false);
}

/*

Initialize scene, load all assets.

*/
void FrankyFishScene::on_setup() {

	m_is_play_enabled = true;
	m_scene_state = SCENE_STATE_NOT_READY;

	load_common_textures();
	load_common_sounds();
	load_dollar_spritepool();
	load_plant_spritepool();

	m_scene_repository = new SceneLoader();

	m_ptr_franky = new FrankySprite();
	m_ptr_franky->enable_sound(m_is_sound_enabled);

	m_ptr_play = new ButtonSprite("res/sprites/play_button.png", make_size(271, 90));
	m_ptr_play->animator(new ForwardAnimator(2, 500));
	m_ptr_play->use_screen_positioning(true);
	m_ptr_play->position(230, 900);
	
	m_ptr_try_again = new ButtonSprite("res/sprites/continue.png", make_size(432, 128));	
	m_ptr_try_again->use_screen_positioning(true);
	m_ptr_try_again->position(142, 800);

	m_gameitems = m_scene_repository->load_gameitems();

	load_scene();

	for (Sprite* sprite : m_gameitems) {
		register_sprite(sprite);
	}

	set_stage();
	register_message_handling();

	// for debugging, show collision rectangles.
	Graphics::instance()->visible_bounding_box(false);

}

void FrankyFishScene::on_begin() {
	//m_splash_timer.start(1500);
	m_ptr_franky->reset();

	m_score = 0;
	m_scene_state = SCENE_STATE_READY_PLAYER_ONE;
	disable_sprite_updates();
	Graphics::instance()->animation_on(false);
	m_ptr_background->x(0.0f);
	m_ptr_background->y(0.0f);
}


/*

Handle keyboard input for playing on a pc.

*/
void FrankyFishScene::on_check_input(InputManager* ptr_input_manager) {

	bool is_F1_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_F1);
	bool is_escape_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_ESCAPE);
	bool is_up_pressed = ptr_input_manager->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT) ||
		ptr_input_manager->is_key_pressed(SDL_SCANCODE_UP);
	bool is_no_input_happening = is_no_touch_happening(ptr_input_manager);
	bool is_pause_button_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_P);
	bool is_un_pause_button_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_U);
	bool is_back_button_pressed = ptr_input_manager->is_device_closing_app();

	// if escape key is pressed, exit immediately.
	if (is_escape_pressed || is_back_button_pressed) {
		stop();
	}

	if (is_pause_button_pressed) {
		pause();
		return;
	}

	if (is_un_pause_button_pressed) {
		resume();
	}

	if (is_F1_pressed)
		m_ptr_franky->immortal(true);

	switch (m_scene_state) {
	case SCENE_STATE_PLAYING:
		handle_playing_input(is_up_pressed);
		break;

	case SCENE_STATE_GAME_OVER:
		handle_game_over_input(ptr_input_manager, is_up_pressed);
		break;

	case SCENE_STATE_READY_PLAYER_ONE:
		handle_player_ready_input(ptr_input_manager, is_up_pressed);
		// cheesy workaround alert. sprite updates are disabled when in ready state.
		m_ptr_play->animate();
		break;
	}
}




/*

Frame update.

*/
void FrankyFishScene::on_update() {


	m_ptr_franky->on_update();

	if (m_scene_state != SCENE_STATE_PLAYING)
		return;

	list<Sprite*>* plant_list = m_plants.get_sprite_list();
	for (list<Sprite*>::iterator itr = plant_list->begin(); itr != plant_list->end(); ++itr)
	{
		Sprite* sprite = (Sprite*)(*itr);
		if (sprite->position_x() < Camera::instance()->position_x() - 300) {
			m_plants.release_deferred(sprite);
		}
	}

	m_plants.flush();

	add_plant();

	move_camera();

	/*	if (m_ptr_franky->position_y() < CAMERA_FOLLOW_THRESHOLD_TOP) {
	float franky_y = m_ptr_franky->position_y();
	float new_y = CAMERA_NORMAL_Y_POSITION - (CAMERA_FOLLOW_THRESHOLD_TOP - franky_y);
	if (new_y < 0.0f)
	new_y = 0.0f;
	ptr_camera->position_y(new_y);
	}
	else {
	ptr_camera->position_y(CAMERA_NORMAL_Y_POSITION);
	}*/
}



/*

Render the scene for current frame.

*/
void FrankyFishScene::on_render(Graphics* ptr_graphics) {
	Camera* ptr_camera = Camera::instance();

	ptr_graphics->render(m_ptr_background);

	ptr_graphics->render(&m_plants);

	Rect tile_source_rect;
	tile_source_rect.x = 0;
	tile_source_rect.y = 0;

	uint32_t first_tile_x = ((int)ptr_camera->position_x()) / TILE_WIDTH;
	uint32_t last_tile_x = first_tile_x + 10;

	if (first_tile_x >= 10)
		first_tile_x -= 10;
	else
		first_tile_x = 0;

	float tile_render_x;
	float tile_render_y;

	for (uint32_t tile_x = first_tile_x; tile_x < last_tile_x; tile_x++) {
		for (uint32_t tile_y = 0; tile_y < TILE_MAP_HEIGHT; tile_y++) {

			Tile* tile = m_map->tile_at(tile_x, tile_y);
			if (tile != nullptr && tile->tile_type()) {
				tile_render_x = tile_x * TILE_WIDTH;
				tile_render_y = tile_y * TILE_HEIGHT;
				tile_source_rect.w = tile->size()->x;
				tile_source_rect.h = tile->size()->y;
				ptr_graphics->render(tile->texture(), tile_render_x, tile_render_y, &tile_source_rect, tile->flip(), tile->rotation());

				// render collision regions for debug. remove this for release.
				//Rect box_rect;
				//for each (Rect* rect in *(tile->collision_regions())) {
				//	box_rect.x = Camera::instance()->x_to_screen(tile_render_x + rect->x);
				//	box_rect.y = Camera::instance()->y_to_screen(tile_render_y + rect->y);
				//	box_rect.w = rect->w;
				//	box_rect.h = rect->h;
				//	ptr_graphics->render(&box_rect);
				//}

				if (m_scene_state == SCENE_STATE_PLAYING && tile->have_collided(m_ptr_franky->collision_rect())) {
					if (!m_ptr_franky->immortal()) {
						m_ptr_franky->die();
						end_game();
					}
				}
			}
		}
	}

	for (Sprite* sprite : m_gameitems) {
		ptr_graphics->render(sprite);
	}

	ptr_graphics->render(m_ptr_franky);
	ptr_graphics->render(&m_dollar_pool);

	if (m_scene_state == SCENE_STATE_READY_PLAYER_ONE) {
		m_ptr_ready->x(m_ptr_franky->position_x()+50);
		m_ptr_ready->y(m_ptr_franky->position_y()-120);
		ptr_graphics->render(m_ptr_ready);
		ptr_graphics->render(m_ptr_play);
	}

	if (m_scene_state == SCENE_STATE_GAME_OVER) {
		m_ptr_game_over->x(ptr_camera->position_x() + 153);
		m_ptr_top_score->x(ptr_camera->position_x() + 142);
		//m_ptr_try_again->position_x(ptr_camera->position_x() + 142);
		ptr_graphics->render(m_ptr_game_over);
		ptr_graphics->render(m_ptr_top_score);
		ptr_graphics->render(m_ptr_try_again);

		int score_x = 500.0f - get_padding_for_number(m_score);
		int top_score_x = 500.0f - get_padding_for_number(m_top_score);

		ptr_graphics->render(m_score, m_ptr_numbers, 37, 4, score_x, 540.0f);
		ptr_graphics->render(m_top_score, m_ptr_numbers, 37, 4, top_score_x, 630.0f);
	}
	else {
		ptr_graphics->render(m_score, m_ptr_numbers, 37, 4, 500.0f, 15.0f);
	}
}

void FrankyFishScene::on_end() {

}

void FrankyFishScene::on_cleanup() {
}

void FrankyFishScene::on_detect_collisions() {
	if (!m_scene_state == SCENE_STATE_PLAYING)
		return;

	for (Sprite* ptr_sprite : m_gameitems)
	{
		m_ptr_collision_detector->detect(m_ptr_franky, ptr_sprite);
	}
}

void FrankyFishScene::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {
	if (message_type == MESSAGE_TYPE_DEAD) {
		end_game();
		return;
	}
	if (message_type == MESSAGE_TYPE_REWARD_COLLECTED && m_is_play_enabled) {
		RewardSprite* sprite = (RewardSprite*)ptr_sender;
		//m_gameitems.remove(sprite);
		sprite->is_visible(false);
		//unregister_sprite(sprite);
		m_score += sprite->points();

		if (m_is_sound_enabled)
			m_ptr_sound_coin_collected->play_sound();

		for (int c = 0; c < 5; c++) {
			DollarSprite* dollar_sprite = (DollarSprite*)m_dollar_pool.obtain();
			if (dollar_sprite) {
				float heading = c < 3 ? Random::rand_float(0.0f, 180.0f) : Random::rand_float(180.0f, 359.0f);
				dollar_sprite->init(sprite->position_x(), sprite->position_y(), heading);
				register_sprite(dollar_sprite);
			}
		}

		return;
	}
	if (message_type == MESSAGE_TYPE_DOLLAR_COMPLETED) {
		DollarSprite* sprite = (DollarSprite*)ptr_sender;
		unregister_sprite(sprite);
		m_dollar_pool.release(sprite);
	}
	if (message_type == MESSAGE_TYPE_EXTRA_LIFE) {
		Sprite* heart_sprite = (Sprite*)ptr_data;
		m_respawn_position.x = heart_sprite->position_x();
		m_respawn_position.y = heart_sprite->position_y();
		heart_sprite->is_visible(false);
	}
}

