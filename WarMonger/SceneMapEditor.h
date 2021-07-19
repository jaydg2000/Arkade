#pragma once
#include <Scene.h>
#include "TiledMap.h"

using namespace arkade;

class SceneMapEditor : public Scene
{
public:
	SceneMapEditor();
	~SceneMapEditor();

	void							open_map(const char* filename);

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
	TiledMap*						_ptr_map;
	const char*						_filename;
	Rect							_map_viewport;
};

