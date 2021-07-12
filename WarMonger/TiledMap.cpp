#include "TiledMap.h"
#include <Camera.h>

TiledMap::TiledMap()
{	
}

TiledMap::~TiledMap()
{
}

void TiledMap::tile_at(uint16_t x, uint16_t y, uint32_t tile_type_id)
{
	_map[x][y] = tile_type_id;
}

uint16_t TiledMap::tile_at(uint16_t x, uint16_t y)
{
	return _map[x][y];
}

uint16_t TiledMap::tile_at_xy(float x, float y)
{
	// this will return the tile located at the x,y screen coordinates
	// assumes the coordinates are adjusted within the viewport.
	auto ptr_camera = Camera::instance();

	float relative_x = x + ptr_camera->position_x();
	float relative_y = y + ptr_camera->position_y();

	int desired_tile_x = relative_x / TILE_WIDTH;
	int desired_tile_y = relative_y / TILE_HEIGHT;

	return _map[desired_tile_x][desired_tile_y];
}
