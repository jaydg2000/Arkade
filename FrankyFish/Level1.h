#pragma once

#include <Level.h>

using namespace arkade;

class Level1 : public Level
{
public:
	Level1();
	~Level1();

protected:
	virtual void					on_setup();
	virtual void					on_begin_scene(Scene* scene) override;
	virtual void					on_end_scene(Scene* scene) override;
	void							set_audio_options(bool sound_on, bool music_on);
	bool							sound_on();
	bool							music_on();

private:
	Scene*							m_ptr_scene_splash;
	Scene*							m_ptr_scene_franky_first_swim;
	bool							m_is_sound_on;
	bool							m_is_music_on;
};

