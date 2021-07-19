#pragma once
#include <vector>
#include "TiledMap.h"

using namespace std;

class MapLoader
{
public:
	MapLoader();
	~MapLoader();

	TiledMap*				load_map(const char* psz_filename);
	void					save_map(const char* psz_filename, TiledMap* map);
	void					get_all_maps(vector<const char*>* maps);
};

