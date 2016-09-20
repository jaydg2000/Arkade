#include "SceneFrankysFirstSwim.h"



SceneFrankysFirstSwim::SceneFrankysFirstSwim()
{
	m_ptr_collision_detector = new BoundingBoxCollisionDetector();	
}


SceneFrankysFirstSwim::~SceneFrankysFirstSwim()
{
}


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

	m_franky_start_x = FRANKY_START_X;
	m_franky_start_y = FRANKY_START_Y;

	m_ptr_ground = new Image("res/sprites/sprite_ground.png", make_size(1536,137));
	m_ptr_ground->x(0);
	m_ptr_ground->y(1344);
	//m_ptr_ground->use_screen_positioning(true);

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
	m_ptr_ready = new Image("res/sprites/ready.png", make_size(363, 198), m_franky_start_x + 50, m_franky_start_y-125);
	
	register_sprite(m_ptr_franky);
	register_sprite(m_ptr_wave1);
	register_sprite(m_ptr_wave2);
	register_sprite(m_ptr_wave3);

	register_for_messages(MESSAGE_TYPE_DEAD);
	register_for_messages(MESSAGE_TYPE_SCORE);

	Camera::instance()->position(0, CAMERA_NORMAL_Y_POSITION);
}

void SceneFrankysFirstSwim::set_stage() {

	for each (Sprite* sprite in m_predators) {
		unregister_sprite(sprite);
	}
	for each (Sprite* sprite in m_rewards) {
		unregister_sprite(sprite);
	}
	
	m_scene_repository->reload_fish();

	m_predators = m_scene_repository->load_bad_fish();
	m_rewards = m_scene_repository->load_rewards();
	
	for each (Sprite* sprite in m_predators) {
		register_sprite(sprite);
	}
	for each (Sprite* sprite in m_rewards) {
		register_sprite(sprite);
	}
}

void SceneFrankysFirstSwim::on_begin() {
	m_ptr_franky->reset();
	m_ptr_franky->position(m_franky_start_x, m_franky_start_y);
	m_score = 0;
	m_scene_state = SCENE_STATE_READY_PLAYER_ONE;
	Graphics::instance()->animation_on(true);
}

void SceneFrankysFirstSwim::on_check_keyboard_input(Keyboard* ptr_keyboard) {

	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_ESCAPE)) {
		stop();
	}

	if (!m_scene_state != SCENE_STATE_PLAYING && !m_can_move_to_next_state) {
		m_can_move_to_next_state = is_no_touch_happening(ptr_keyboard);
		if (!m_can_move_to_next_state) {
			return;
		}
	}

	if (m_scene_state == SCENE_STATE_GAME_OVER) {
		if (m_ptr_franky->can_restart() && m_can_move_to_next_state) {
			if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_UP)) {
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
		if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_UP)) {
			m_scene_state = SCENE_STATE_PLAYING;
			return;
		}
	}

	if (m_scene_state == SCENE_STATE_PLAYING) {
		if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_UP)) {
			m_ptr_franky->swim();
		}
		else {
			m_ptr_franky->idle();
		}
	}
}

void SceneFrankysFirstSwim::on_mouse_button(uint32_t button_event_type) {
}

void SceneFrankysFirstSwim::on_update() {
	if (m_scene_state != SCENE_STATE_PLAYING)
		return;

	for each (Sprite* sprite in m_predators) {
		((PredatorSprite*)sprite)->swim();
	}
	for each (Sprite* sprite in m_rewards) {
		((SwimmingSprite*)sprite)->swim();
	}

	Camera* ptr_camera = Camera::instance();
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

void SceneFrankysFirstSwim::on_render(Graphics* ptr_graphics) {
	ptr_graphics->render(m_ptr_background);
	ptr_graphics->render(m_ptr_wave1);
	ptr_graphics->render(m_ptr_wave2);
	ptr_graphics->render(m_ptr_wave3);
	ptr_graphics->render(m_ptr_ground);
	
	for each (Sprite* sprite in m_predators) {
		ptr_graphics->render(sprite);
	}
	for each (Sprite* sprite in m_rewards) {
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
	delete m_ptr_franky;
	delete m_ptr_background;
	// TODO: delete sprites in lists.
	delete m_scene_repository;
	delete m_ptr_collision_detector;
}

void SceneFrankysFirstSwim::on_detect_collisions() {
	if (!m_scene_state == SCENE_STATE_PLAYING)
		return;

	for each (Sprite* ptr_predator in m_predators)
	{
		//m_ptr_collision_detector->detect(m_ptr_franky, ptr_predator);
	}
	
}

void SceneFrankysFirstSwim::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {
	if (message_type == MESSAGE_TYPE_DEAD) {
		m_can_move_to_next_state = false;
		m_scene_state = SCENE_STATE_GAME_OVER;
		Graphics::instance()->animation_on(false);
	}
}

bool SceneFrankysFirstSwim::is_no_touch_happening(Keyboard* ptr_keyboard) {
	return !ptr_keyboard->is_key_pressed(SDL_SCANCODE_UP);
}