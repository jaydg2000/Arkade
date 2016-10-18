#pragma once

#include <Scene.h>
#include <Image.h>
#include <StaticAnimator.h>
#include <Random.h>
#include "FrankySprite.h"

using namespace arkade;

#define SCENE_TYPE_SPLASH			2
#define FRANKY_SPLASH_SPEED         2.8f
class SplashScene : public Scene {
public:
	SplashScene();
	~SplashScene();

	bool							is_sound_on();
	bool							is_music_on();

protected:
	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_check_input(InputManager* keyboard);
	virtual void					on_update();
	virtual void					on_render(Graphics* ptr_graphics);
	virtual void					on_end();
	virtual void					on_cleanup();

private:
	Image*							m_ptr_background;
	Image*							m_ptr_image_sound;
	Sprite*							m_ptr_sound_on_off;
	Sprite*							m_ptr_music_on_off;
	Sprite*							m_ptr_play;
	FrankySprite*					m_ptr_franky;
	bool							m_swim_left;
	bool							m_is_sound_on;
	bool							m_is_music_on;

	void							check_franky_position();
	void							position_franky();
	void							flip_franky();
};

