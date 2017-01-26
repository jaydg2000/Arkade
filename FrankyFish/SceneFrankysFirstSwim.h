#pragma once
#include "FrankyFishScene.h"

using namespace arkade;

class SceneFrankysFirstSwim :
	public FrankyFishScene
{
public:
	SceneFrankysFirstSwim();
	~SceneFrankysFirstSwim();

	void									set_audio(bool is_sound_on, bool is_music_on);

protected:
	virtual void							on_setup();
	virtual void							on_begin();
	virtual void							on_check_input(InputManager* keyboard);
	virtual void							on_update();
	virtual void							on_render(Graphics* ptr_graphics);
	virtual void							on_end();
	virtual void							on_cleanup();
	virtual void							on_detect_collisions();
	virtual void							on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

private:
};

