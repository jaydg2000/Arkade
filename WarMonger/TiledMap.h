#pragma once
#include <ArkadeTypes.h>
#include <Graphics.h>
#include "WarMonger_Main.h"
#include "Tile.h"
#include "TileSet.h"

using namespace arkade;

class TiledMap
{
public:
	TiledMap();
	~TiledMap();

	void				tile_at(uint16_t x, uint16_t y, uint16_t);
	uint16_t			tile_at(uint16_t x, uint16_t y);
	uint16_t			tile_at_xy(float x, float y);
	void				render(Graphics* ptr_graphics, Rect viewport);

private:
	uint32_t			_camera_x, _camera_y;
	uint16_t			_map[MAP_WIDTH][MAP_HEIGHT] = { 0 };
	TileSet*			_tile_set;
};

