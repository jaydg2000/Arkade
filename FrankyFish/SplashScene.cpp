#include "SplashScene.h"
#include <TextureCache.h>

SplashScene::SplashScene() {
	type(SCENE_TYPE_SPLASH);
	m_swim_left = false;
	m_is_sound_on = true;
	m_is_music_on = true;
}


SplashScene::~SplashScene() {
}

void SplashScene::on_setup() {
	TextureCache* ptr_texture_cache = TextureCache::instance();

	ptr_texture_cache->push("res/sprites/offon.png", RGB(255, 255, 255));
	ptr_texture_cache->push("res/sprites/sprite_franky_swim_right.png", RGB(255, 255, 255));
	m_ptr_background = new Image("res/sprites/gradient.png", make_size(720, 1280), 0.0f, 0.0f);
	m_ptr_image_sound = new Image("res/sprites/config_sound.png", make_size(432,232), 150, 400);
	m_ptr_sound_on_off = new Sprite("res/sprites/offon.png", make_size(118, 47));
	m_ptr_music_on_off = new Sprite("res/sprites/offon.png", make_size(118, 47));
	m_ptr_play = new Sprite("res/sprites/play.png", make_size(432,128));
	m_ptr_franky = new FrankySprite();
}

void SplashScene::on_begin() {
	m_ptr_sound_on_off->animator(new StaticAnimator(2));
	m_ptr_music_on_off->animator(new StaticAnimator(2));

	m_ptr_sound_on_off->position(440, 450);
	m_ptr_music_on_off->position(440, 535);

	m_ptr_sound_on_off->animator()->current_frame(1);
	m_ptr_music_on_off->animator()->current_frame(1);

	m_ptr_play->position(150, 700);

	m_ptr_franky->position(-100, 100);
}

void SplashScene::on_check_input(InputManager* ptr_input_manager) {
	bool is_escape_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_ESCAPE);
	bool is_mouse_pressed = ptr_input_manager->is_mouse_button_pressed();

	if (is_escape_pressed) {
		end();
	}

	if (is_mouse_pressed) {
		int mx = ptr_input_manager->mouse_x();
		int my = ptr_input_manager->mouse_y();

		if (m_ptr_sound_on_off->intersects_with(mx, my)) {
			if (m_ptr_sound_on_off->animator()->current_frame() == 0) {
				m_ptr_sound_on_off->animator()->current_frame(1);
				m_is_sound_on = true;
			}
			else {
				m_ptr_sound_on_off->animator()->current_frame(0);
				m_is_sound_on = false;
			}
		}

		if (m_ptr_music_on_off->intersects_with(mx, my)) {
			if (m_ptr_music_on_off->animator()->current_frame() == 0) {
				m_ptr_music_on_off->animator()->current_frame(1);
				m_is_music_on = true;
			}
			else {
				m_ptr_music_on_off->animator()->current_frame(0);
				m_is_music_on = false;
			}
		}

		if (m_ptr_play->intersects_with(mx, my)) {
			stop();
		}
	}
}

bool SplashScene::is_sound_on() {
	return m_is_sound_on;
}

bool SplashScene::is_music_on() {
	return m_is_music_on;
}

void SplashScene::on_update() {
	check_franky_position();
	m_ptr_franky->move_relative_x(m_swim_left ? -FRANKY_SPLASH_SPEED : FRANKY_SPLASH_SPEED);
}

void SplashScene::on_render(Graphics* ptr_graphics) {
	ptr_graphics->render(m_ptr_background);
	ptr_graphics->render(m_ptr_franky);
	ptr_graphics->render(m_ptr_image_sound);
	ptr_graphics->render(m_ptr_sound_on_off);
	ptr_graphics->render(m_ptr_music_on_off);
	ptr_graphics->render(m_ptr_play);
}

void SplashScene::on_end() {

}

void SplashScene::on_cleanup() {
	delete m_ptr_image_sound;
	delete m_ptr_sound_on_off;
	delete m_ptr_music_on_off;
	delete m_ptr_play;
	delete m_ptr_franky;
	delete m_ptr_background;
}

void SplashScene::position_franky() {
	m_ptr_franky->position_y(Random::rand_float(50, 1100));
	m_swim_left = !m_swim_left;
	flip_franky();
}

void SplashScene::flip_franky() {
	m_ptr_franky->flip(m_swim_left ? FLIP_HORIZONTAL : FLIP_NONE);
}

void SplashScene::check_franky_position() {
	float x = m_ptr_franky->position_x();
	if (x < -170 || x > 820) {
		position_franky();
		flip_franky();
	}
}