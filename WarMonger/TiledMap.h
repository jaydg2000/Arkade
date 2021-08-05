#pragma once
#include <ArkadeTypes.h>
#include <Graphics.h>
#include "WarMonger_Main.h"
#include "Tile.h"
#include "TileSet.h"
#include "City.h"

using namespace arkade;

class TiledMap
{
public:
	TiledMap();
	~TiledMap();

	void				tile_at(uint16_t x, uint16_t y, uint16_t);
	uint16_t			tile_at(uint16_t x, uint16_t y);
	uint16_t			tile_at_xy(float x, float y);
	uint32_t			screen_to_map_x(uint32_t screen_x);
	uint32_t			screen_to_map_y(uint32_t screen_y);
	uint32_t			map_to_screen_x(uint32_t map_x);
	uint32_t			map_to_screen_y(uint32_t map_y);
	void				render(Graphics* ptr_graphics, Rect viewport);
	void				fill(Tile* tile);
	void				grid(bool display_grid);

private:
	uint16_t			_map[MAP_WIDTH][MAP_HEIGHT] = { 0 };
	TileSet*			_tile_set;
	bool				_render_grid;
};

