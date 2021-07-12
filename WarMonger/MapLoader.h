#pragma once
#include "TiledMap.h"

class MapLoader
{
public:
	MapLoader();
	~MapLoader();

	TiledMap*				load_map(const char* psz_filename);
	void					save_map(const char* psz_filename, TiledMap* map);
};

