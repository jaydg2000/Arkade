#include "SceneFrankysFirstSwim.h"


/*

	Default constructor.

*/
SceneFrankysFirstSwim::SceneFrankysFirstSwim()
{
	type(SCENE_TYPE_GAME);
	m_ptr_collision_detector = new BoundingBoxCollisionDetector();	
	m_ptr_multibox_collision_detector = new MultipleBoundingBoxCollisionDetector();
	m_is_sound_enabled = true;
	m_is_music_enabled = true;
}


/*

	Destructor

*/
SceneFrankysFirstSwim::~SceneFrankysFirstSwim()
{
	delete m_ptr_franky;
	delete m_ptr_background;	
	delete m_scene_repository;
	delete m_ptr_collision_detector;
}


void SceneFrankysFirstSwim::set_audio(bool is_sound_on, bool is_music_on) {
	m_is_sound_enabled = is_sound_on;
	m_is_music_enabled = is_music_on;
}


/*

	Initialize scene, load all assets.

*/
void SceneFrankysFirstSwim::on_setup() {
	m_is_play_enabled = true;
	m_scene_state = SCENE_STATE_NOT_READY;
	//m_is_sound_enabled = false;

	load_textures();
	load_sounds();
	load_dollar_spritepool();

	m_scene_repository = new SceneRepository("res/scene/scene1.scn");
	m_ptr_franky = new FrankySprite();

	load_scene();
	
	// get the game obstacles and register them with the scene.
	set_stage();	
	
	register_message_handling();

	// set camera at the start position.
	Camera::instance()->position(0, CAMERA_NORMAL_Y_POSITION);
	
	// for debugging, show collision rectangles.
	Graphics::instance()->visible_bounding_box(false);

}


/*

	Specify the messages this scene can receive.
	
*/
void SceneFrankysFirstSwim::register_message_handling() {
	register_for_messages(MESSAGE_TYPE_DEAD);
	register_for_messages(MESSAGE_TYPE_SCORE);
	register_for_messages(MESSAGE_TYPE_REWARD_COLLECTED);
	register_for_messages(MESSAGE_TYPE_DOLLAR_COMPLETED);
}

void SceneFrankysFirstSwim::load_scene() {
	// load the tile set and tile map.
	TileSetRepository tile_set_repo;
	m_tile_set = tile_set_repo.load_tile_set();
	TileMapRepository map_repo;
	m_map = map_repo.load_map("res/scene/scene1.scn", m_tile_set);

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

void SceneFrankysFirstSwim::load_textures() {
	TextureCache* ptr_texture_cache = TextureCache::instance();
	ptr_texture_cache->push("res/sprites/sprite_bird3.png", RGB(0, 0, 0));
	ptr_texture_cache->push("res/sprites/sprite_franky_swim_right.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/ready.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/game_over.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/sprite_ground.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/sprite_wave.png", RGB(255, 255, 255));
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


void SceneFrankysFirstSwim::load_sounds() {
	m_ptr_sound_coin_collected = new Sound("res/wav/coin10.wav");
	m_ptr_sound_splash = new Sound("res/wav/splash1.wav");
	m_ptr_sound_death = new Sound("res/wav/death.wav");
	m_ptr_back_track = new Sound("res/wav/jungle.wav");
}

void SceneFrankysFirstSwim::load_dollar_spritepool() {
	for (int c = 0; c < 24; c++) {
		DollarSprite* dollar = new DollarSprite();
		m_dollar_pool.add(dollar);
	}
}

/*

	Get the game sprites loaded and registered.
	
*/
void SceneFrankysFirstSwim::set_stage() {

	// unregister any existing sprites from scene.
	for each (Sprite* sprite in m_gameitems) {
		unregister_sprite(sprite);
	}
	
	// get the reloaded sprites.
	m_gameitems = m_scene_repository->load_gameitems();

	// register the sprites with the scene.
	for each (Sprite* sprite in m_gameitems) {
		register_sprite(sprite);
	}

	m_dollar_pool.release_all();
}



/*

	Beginning of the scene. Put game items in place.

*/
void SceneFrankysFirstSwim::on_begin() {
	//m_splash_timer.start(1500);
	m_ptr_franky->reset();
	m_ptr_franky->position(FRANKY_START_X, FRANKY_START_Y);
	m_score = 0;
	m_scene_state = SCENE_STATE_READY_PLAYER_ONE;
	disable_sprite_updates();
	Graphics::instance()->animation_on(false);
	Camera::instance()->position(0, 0);
	m_ptr_background->x(0.0f);
	m_ptr_background->y(0.0f);
}



/*

	Handle keyboard input for playing on a pc.

*/
void SceneFrankysFirstSwim::on_check_input(InputManager* ptr_input_manager) {

	bool is_F1_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_F1);
	bool is_escape_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_ESCAPE);
	bool is_up_pressed = ptr_input_manager->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT) ||
		ptr_input_manager->is_key_pressed(SDL_SCANCODE_UP);
	bool is_no_input_happening = is_no_touch_happening(ptr_input_manager);
	bool is_pause_button_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_P);
	bool is_un_pause_button_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_U);

	// if escape key is pressed, exit immediately.
	if (is_escape_pressed) {
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
			handle_game_over_input(is_up_pressed);
			break;

		case SCENE_STATE_READY_PLAYER_ONE:
			handle_player_ready_input(is_up_pressed);
			break;
	}
}


void SceneFrankysFirstSwim::handle_player_ready_input(bool is_up_pressed) {
	if (is_up_pressed) {
		m_scene_state = SCENE_STATE_PLAYING;
		enable_sprite_updates();
		Graphics::instance()->animation_on(true);
		if (m_is_music_enabled)
			m_ptr_back_track->play_sound(true);
		return;
	}
}


void SceneFrankysFirstSwim::handle_playing_input(bool is_up_pressed) {
	
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
	} else {
		m_is_play_enabled = true;
		m_ptr_franky->rest();
	}
}


void SceneFrankysFirstSwim::handle_game_over_input(bool is_up_pressed) {
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


/*

	Frame update.

*/
void SceneFrankysFirstSwim::on_update() {

	m_ptr_franky->on_update();

	if (m_scene_state != SCENE_STATE_PLAYING)
		return;	

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
void SceneFrankysFirstSwim::on_render(Graphics* ptr_graphics) {
	Camera* ptr_camera = Camera::instance();

	ptr_graphics->render(m_ptr_background);

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

	for each (Sprite* sprite in m_gameitems) {
		ptr_graphics->render(sprite);
	}

	ptr_graphics->render(m_ptr_franky);
	ptr_graphics->render(&m_dollar_pool);

	if (m_scene_state == SCENE_STATE_READY_PLAYER_ONE) {
		ptr_graphics->render(m_ptr_ready);
	}

	if (m_scene_state == SCENE_STATE_GAME_OVER) {
		m_ptr_game_over->x(ptr_camera->position_x() + 150);
		ptr_graphics->render(m_ptr_game_over);
	}

	ptr_graphics->render(m_score, m_ptr_numbers, 30, 4, 500.0f, 10.0f);
}

void SceneFrankysFirstSwim::on_end() {

}

void SceneFrankysFirstSwim::on_cleanup() {
}

void SceneFrankysFirstSwim::on_detect_collisions() {
	if (!m_scene_state == SCENE_STATE_PLAYING)
		return;



	for each (Sprite* ptr_sprite in m_gameitems)
	{
		m_ptr_collision_detector->detect(m_ptr_franky, ptr_sprite);
	}
}

void SceneFrankysFirstSwim::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {
	if (message_type == MESSAGE_TYPE_DEAD) {
		end_game();
		return;
	}
	if (message_type == MESSAGE_TYPE_REWARD_COLLECTED && m_is_play_enabled) {
		RewardSprite* sprite = (RewardSprite*)ptr_sender;		
		m_gameitems.remove(sprite);
		sprite->is_visible(false);
		unregister_sprite(sprite);
		m_score += sprite->points();
		if(m_is_sound_enabled)
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
}

bool SceneFrankysFirstSwim::is_no_touch_happening(InputManager* ptr_input_manager) {
	return !ptr_input_manager->is_key_pressed(SDL_SCANCODE_UP);
}

void SceneFrankysFirstSwim::move_camera() {
	Camera* ptr_camera = Camera::instance();
	ptr_camera->move_relative_x(CAMERA_SPEED);
	m_ptr_franky->move_relative_x(CAMERA_SPEED);
	//m_ptr_background->x(m_ptr_background->x() + CAMERA_SPEED);
}

void SceneFrankysFirstSwim::end_game() {
	if (m_is_music_enabled)
		m_ptr_back_track->stop_sound();
	m_is_play_enabled = false;
	m_scene_state = SCENE_STATE_GAME_OVER;
	Graphics::instance()->animation_on(false);
	disable_sprite_updates();
	if(m_is_sound_enabled)
		m_ptr_sound_death->play_sound();
}