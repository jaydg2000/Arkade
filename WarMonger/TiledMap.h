#pragma once
#include <ArkadeTypes.h>
#include "WarMonger_Main.h"
#include "Tile.h"

using namespace arkade;

class TiledMap
{
public:
	TiledMap();
	~TiledMap();

	void				tile_at(uint16_t x, uint16_t y, uint32_t);
	uint16_t			tile_at(uint16_t x, uint16_t y);
	uint16_t			tile_at_xy(float x, float y);

private:
	uint32_t			_x, _y;
	uint16_t			_map[MAP_WIDTH][MAP_HEIGHT] = { 0 };
};

