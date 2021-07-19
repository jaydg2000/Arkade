#pragma once
#include <vector>
#include <Scene.h>
#include <MenuForm.h>
#include <Font.h>

using namespace arkade;

class SceneChooseMap : public Scene
{
public:
	SceneChooseMap();
	~SceneChooseMap();

	virtual void					on_setup();
	//virtual void					on_check_input(InputManager* keyboard);
	//virtual void					on_update();
	//virtual void					on_render(Graphics* ptr_graphics);
	virtual void					on_cleanup();

private:
	vector<const char*>*			_ptr_maps;
	MenuForm*						_map_menu;
	Font*							_ptr_font;
};

