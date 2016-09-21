#include "SceneFrankysFirstSwim.h"



SceneFrankysFirstSwim::SceneFrankysFirstSwim()
{
	m_ptr_collision_detector = new BoundingBoxCollisionDetector();	
}



SceneFrankysFirstSwim::~SceneFrankysFirstSwim()
{
	delete m_ptr_franky;
	delete m_ptr_background;
	// TODO: delete sprites in lists.
	delete m_scene_repository;
	delete m_ptr_collision_detector;
}



/*

	Initialize scene, load all assets.

*/
void SceneFrankysFirstSwim::on_setup() {
	TextureCache* ptr_texture_cache = TextureCache::instance();
	m_can_move_to_next_state = true;
	m_scene_state = SCENE_STATE_NOT_READY;	
	ptr_texture_cache->push("res/sprites/sprite_bird3.png", RGB(0,0,0));
	ptr_texture_cache->push("res/sprites/sprite_franky_swim_right.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/sprite_toothy_fish_1.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/ready.png", RGB(255,255,255));
	ptr_texture_cache->push("res/sprites/sprite_ground.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/sprite_wave.png", RGB(255, 255, 255));
	m_scene_repository = new SceneRepository("res/scene/scene1.fsh");
	set_stage();
	
	m_ptr_ground = new Image("res/sprites/sprite_ground.png", make_size(1536,137));
	m_ptr_ground->x(0);
	m_ptr_ground->y(1344);

	m_ptr_franky = new FrankySprite();	

	m_ptr_wave1 = new Sprite("res/sprites/sprite_wave.png", make_size(255, 258));
	m_ptr_wave2 = new Sprite("res/sprites/sprite_wave.png", make_size(255, 258));
	m_ptr_wave3 = new Sprite("res/sprites/sprite_wave.png", make_size(255, 258));
	m_ptr_wave1->animator(new RandomAnimator(4, 100));
	m_ptr_wave2->animator(new RandomAnimator(4, 100));
	m_ptr_wave3->animator(new RandomAnimator(4, 100));
	m_ptr_wave1->position(0, WAVE_SPRITE_Y_POSITION);
	m_ptr_wave2->position(255, WAVE_SPRITE_Y_POSITION);
	m_ptr_wave3->position(510, WAVE_SPRITE_Y_POSITION);
	

	m_ptr_background = new Image("res/sprites/background.png", make_size(720,1480), 0.0f, 0.0f);
	m_ptr_ready = new Image("res/sprites/ready.png", make_size(363, 198), FRANKY_START_X + 50, FRANKY_START_Y-125);

	register_sprite(m_ptr_franky);
	register_sprite(m_ptr_wave1);
	register_sprite(m_ptr_wave2);
	register_sprite(m_ptr_wave3);

	register_for_messages(MESSAGE_TYPE_DEAD);
	register_for_messages(MESSAGE_TYPE_SCORE);
	register_for_messages(MESSAGE_TYPE_REWARD_COLLECTED);

	Camera::instance()->position(0, CAMERA_NORMAL_Y_POSITION);
}



/*

	Get the game sprites loaded and registered.
	
*/
void SceneFrankysFirstSwim::set_stage() {

	// unregister any existing sprites from scene.
	for each (Sprite* sprite in m_gameitems) {
		unregister_sprite(sprite);
	}
	
	// force a reload of the scene file and sprites.
	m_scene_repository->reload_gameitems();

	// get the reloaded sprites.
	m_gameitems = m_scene_repository->load_gameitems();

	// register the sprites with the scene.
	for each (Sprite* sprite in m_gameitems) {
		register_sprite(sprite);
	}
}



/*

	Beginning of the scene. Put game items in place.

*/
void SceneFrankysFirstSwim::on_begin() {
	m_swim_timer.start(20);
	m_ptr_franky->reset();
	m_ptr_franky->position(FRANKY_START_X, FRANKY_START_Y);
	m_score = 0;
	m_scene_state = SCENE_STATE_READY_PLAYER_ONE;
	disable_sprite_updates();
	Graphics::instance()->animation_on(false);
}



/*

	Handle keyboard input for playing on a pc.

*/
void SceneFrankysFirstSwim::on_check_input(InputManager* ptr_input_manager) {

	if (ptr_input_manager->is_key_pressed(SDL_SCANCODE_ESCAPE)) {
		stop();
	}

	if (m_scene_state == SCENE_STATE_PLAYING && !m_can_move_to_next_state) {
		m_can_move_to_next_state = is_no_touch_happening(ptr_input_manager);
		if (!m_can_move_to_next_state) {
			return;
		}
	}

	if (m_scene_state == SCENE_STATE_GAME_OVER) {
		if (m_ptr_franky->can_restart() && m_can_move_to_next_state) {
			if (ptr_input_manager->is_key_pressed(SDL_SCANCODE_UP)) {
				m_scene_state = SCENE_STATE_READY_PLAYER_ONE;
				set_stage();
				on_begin();	
				m_ptr_franky->reset();
				m_can_move_to_next_state = false;
				return;
			}
		}
	}

	if (m_scene_state == SCENE_STATE_READY_PLAYER_ONE  && m_can_move_to_next_state) {
		if (ptr_input_manager->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT) ||
			ptr_input_manager->is_key_pressed(SDL_SCANCODE_UP)) {
			m_scene_state = SCENE_STATE_PLAYING;
			enable_sprite_updates();
			Graphics::instance()->animation_on(true);
			return;
		}
	}

	if (m_scene_state == SCENE_STATE_PLAYING) {
		if (ptr_input_manager->is_mouse_button_pressed(MOUSE_BUTTON_INPUT_LEFT) ||
			ptr_input_manager->is_key_pressed(SDL_SCANCODE_UP)) {

			if (m_ptr_franky->position_y() < MIN_Y_JUMP_POSITION) {
				m_ptr_franky->jump();
			}
			else {
				m_ptr_franky->boost();
			}
			m_can_move_to_next_state = false;

		}
		else {
			m_ptr_franky->rest();
		}
	}
}



/*

	Mouse handling. SDL simulates mouse clicks for mobile touches.

*/
void SceneFrankysFirstSwim::on_mouse_button(uint32_t button_event_type) {
}



/*

	Frame update.

*/
void SceneFrankysFirstSwim::on_update() {
	if (m_scene_state != SCENE_STATE_PLAYING)
		return;	

	Camera* ptr_camera = Camera::instance();

	if (m_swim_timer.has_elapsed()) {
		ptr_camera->move_relative_x(CAMERA_SPEED);
		m_ptr_franky->move_relative_x(CAMERA_SPEED);
		m_ptr_background->x(m_ptr_background->x() + CAMERA_SPEED);
		m_ptr_wave1->move_relative_x(CAMERA_SPEED);
		m_ptr_wave2->move_relative_x(CAMERA_SPEED);
		m_ptr_wave3->move_relative_x(CAMERA_SPEED);
		m_ptr_ground->x(m_ptr_ground->x() + GROUND_SPEED);
	}
	
	if (m_ptr_franky->position_y() < CAMERA_FOLLOW_THRESHOLD_TOP) {
		float franky_y = m_ptr_franky->position_y();
		float new_y = CAMERA_NORMAL_Y_POSITION - (CAMERA_FOLLOW_THRESHOLD_TOP - franky_y);
		if (new_y < 0.0f)
			new_y = 0.0f;
		ptr_camera->position_y(new_y);
	}
	else {
		ptr_camera->position_y(CAMERA_NORMAL_Y_POSITION);
	}
	
}



/*

	Render the scene for current frame.

*/
void SceneFrankysFirstSwim::on_render(Graphics* ptr_graphics) {

	// render environment.
	ptr_graphics->render(m_ptr_background);
	ptr_graphics->render(m_ptr_wave1);
	ptr_graphics->render(m_ptr_wave2);
	ptr_graphics->render(m_ptr_wave3);
	ptr_graphics->render(m_ptr_ground);
	

	// render all game sprites including fish, bugs
	for each (Sprite* sprite in m_gameitems) {
		ptr_graphics->render(sprite);
	}

	ptr_graphics->render(m_ptr_franky);

	if (m_scene_state == SCENE_STATE_READY_PLAYER_ONE) {
		ptr_graphics->render(m_ptr_ready);
	}
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
		//m_ptr_collision_detector->detect(m_ptr_franky, ptr_sprite);
	}
}

void SceneFrankysFirstSwim::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {
	if (message_type == MESSAGE_TYPE_DEAD) {
		m_can_move_to_next_state = false;
		m_scene_state = SCENE_STATE_GAME_OVER;
		Graphics::instance()->animation_on(false);
		return;
	}
	if (message_type == MESSAGE_TYPE_REWARD_COLLECTED) {
		m_gameitems.remove((Sprite*)ptr_sender);
		return;
	}
}

bool SceneFrankysFirstSwim::is_no_touch_happening(InputManager* ptr_input_manager) {
	return !ptr_input_manager->is_key_pressed(SDL_SCANCODE_UP);
}