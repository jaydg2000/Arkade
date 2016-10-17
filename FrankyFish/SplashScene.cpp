#include "stdafx.h"
#include "SplashScene.h"
#include <TextureCache.h>

SplashScene::SplashScene() {
	type(SCENE_TYPE_SPLASH);
}


SplashScene::~SplashScene() {
}

void SplashScene::on_setup() {
	TextureCache* ptr_texture_cache = TextureCache::instance();

	ptr_texture_cache->push("res/sprites/offon.png", RGB(255, 255, 255));
	m_ptr_image_sound = new Image("res/sprites/config_sound.png", make_size(432,232), 150, 400);
	m_ptr_sound_on_off = new Sprite("res/sprites/offon.png", make_size(118, 47));
	m_ptr_music_on_off = new Sprite("res/sprites/offon.png", make_size(118, 47));
}

void SplashScene::on_begin() {
	m_ptr_sound_on_off->animator(new StaticAnimator(2));
	m_ptr_music_on_off->animator(new StaticAnimator(2));

	m_ptr_sound_on_off->position(440, 450);
	m_ptr_music_on_off->position(440, 535);

	m_ptr_sound_on_off->animator()->current_frame(1);
	m_ptr_music_on_off->animator()->current_frame(1);
}

void SplashScene::on_check_input(InputManager* ptr_input_manager) {
	bool is_escape_pressed = ptr_input_manager->is_key_pressed(SDL_SCANCODE_ESCAPE);
	bool is_mouse_pressed = ptr_input_manager->is_mouse_button_pressed();

	if (is_escape_pressed) {
		stop();
	}

	if (is_mouse_pressed) {
		int mx = ptr_input_manager->mouse_x();
		int my = ptr_input_manager->mouse_y();

		if (m_ptr_sound_on_off->intersects_with(mx, my)) {
			if (m_ptr_sound_on_off->animator()->current_frame() == 0)
				m_ptr_sound_on_off->animator()->current_frame(1);
			else
				m_ptr_sound_on_off->animator()->current_frame(0);
		}

		if (m_ptr_music_on_off->intersects_with(mx, my)) {
			if (m_ptr_music_on_off->animator()->current_frame() == 0)
				m_ptr_music_on_off->animator()->current_frame(1);
			else
				m_ptr_music_on_off->animator()->current_frame(0);
		}

	}
}

bool SplashScene::is_sound_on() {
	return m_ptr_sound_on_off->animator()->current_frame() == 1;
}

bool SplashScene::is_music_on() {
	return m_ptr_music_on_off->animator()->current_frame() == 1;
}

void SplashScene::on_update() {

}

void SplashScene::on_render(Graphics* ptr_graphics) {
	ptr_graphics->render(m_ptr_image_sound);
	ptr_graphics->render(m_ptr_sound_on_off);
	ptr_graphics->render(m_ptr_music_on_off);
}

void SplashScene::on_end() {

}

void SplashScene::on_cleanup() {

}
