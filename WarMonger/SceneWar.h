#pragma once
#include <Scene.h>
#include <BoundingBoxCollisionDetector.h>
#include <Image.h>
#include "TiledMap.h"
#include <Font.h>
#include <Text.h>
#include <IntervalLogic.h>

using namespace arkade;

class SceneWar : public Scene 
{
public:
	SceneWar();
	~SceneWar();


	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_check_input(InputManager* ptr_keyboard);
	virtual void					on_update();
	virtual void					on_render(Graphics* ptr_graphics);
	virtual void					on_end();
	virtual void					on_cleanup();
	virtual void					on_detect_collisions();
	virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

private:
	Image*							_commandCenterImage;
	TiledMap*						_ptr_map;
	Font*							_ptr_font;
	Text*							_ptr_text;
	uint32_t						_rotation;
	IntervalLogic*					_interval;
};

