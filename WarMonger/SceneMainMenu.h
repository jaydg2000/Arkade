#pragma once
#include <Scene.h>
#include <Font.h>
#include <Button.h>
#include <Text.h>

using namespace arkade;

class SceneMainMenu : public Scene
{
public:
	SceneMainMenu();
	~SceneMainMenu();

protected:
	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_check_input(InputManager* keyboard);
	virtual void					on_update();
	virtual void					on_render(Graphics* ptr_graphics);
	virtual void					on_end();
	virtual void					on_cleanup();
	virtual void					on_detect_collisions();
	virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

private:
	Text*							_ptr_text_button_play;
	Font*							_ptr_font_button;
	Button*							_ptr_button_play;
};

