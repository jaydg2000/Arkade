#include "Level1.h"
#include "SplashScene.h"
#include "SceneFrankysFirstSwim.h"

Level1::Level1() {
	m_is_music_on = true;
	m_is_sound_on = true;
}


Level1::~Level1() {
}

void Level1::on_setup() {
	m_ptr_scene_splash = new SplashScene();
	m_ptr_scene_franky_first_swim = new SceneFrankysFirstSwim();

	add_scene(m_ptr_scene_splash);
	add_scene(m_ptr_scene_franky_first_swim);
}

void Level1::set_audio_options(bool sound_on, bool music_on) {
	m_is_sound_on = sound_on;
	m_is_music_on = music_on;
}

bool Level1::sound_on() {
	return m_is_sound_on;
}

bool Level1::music_on() {
	return m_is_music_on;
}

void Level1::on_begin_scene(Scene* scene) {
	if (scene->type() == SCENE_TYPE_GAME) {
		bool is_sound_on = ((SplashScene*)m_ptr_scene_splash)->is_sound_on();
		bool is_music_on = ((SplashScene*)m_ptr_scene_splash)->is_music_on();
		((SceneFrankysFirstSwim*)m_ptr_scene_franky_first_swim)->set_audio(is_sound_on, is_music_on);
	}
}

void Level1::on_end_scene(Scene* scene) {
}