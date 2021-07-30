#include "SceneChooseMap.h"
#include "MapLoader.h"

SceneChooseMap::SceneChooseMap()
{
	_ptr_maps = new vector<const char*>();
}

SceneChooseMap::~SceneChooseMap()
{
	//for (const char* filename : *_ptr_maps)
	//{
	//	
	//	delete filename;		
	//}
	_ptr_maps->clear();
	delete _ptr_maps;
}

void SceneChooseMap::on_setup()
{
	MapLoader map_loader;
	map_loader.get_all_maps(_ptr_maps);

	_ptr_font = new Font("fonts/bahnschrift.ttf", 15);
	_map_menu = new MenuForm(make_size(RES_WIDTH, RES_HEIGHT), _ptr_font);

	//_map_menu->add_menu_item("New", [this]() {
	//	result((void*)"new-map.map");		
	//});
	for (const char* filename : *_ptr_maps)
	{
		_map_menu->add_menu_item(filename, [this, filename]() 
		{
			_map_menu->disable();
			_map_menu->hide();			
			result((void*)filename);			
			stop();
		});
	}
	_map_menu->add_menu_item("Back", [this](){
		_map_menu->disable();
		_map_menu->hide();
		stop();
	});

	register_form(_map_menu->form());
	_map_menu->show();
	_map_menu->enable();	
}

void SceneChooseMap::on_cleanup()
{	
	unregister_form(_map_menu->form());
	delete _ptr_font;
	delete _map_menu;
}
