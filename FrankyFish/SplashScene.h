#pragma once

#include <Scene.h>
#include <Image.h>
#include <StaticAnimator.h>

using namespace arkade;

#define SCENE_TYPE_SPLASH			2

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
	Image*							m_ptr_image_sound;
	Sprite*							m_ptr_sound_on_off;
	Sprite*							m_ptr_music_on_off;
};

