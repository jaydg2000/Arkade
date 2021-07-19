#include "TiledMap.h"
#include <Camera.h>

TiledMap::TiledMap()
{	
	_camera_x = _camera_y = 0;
	_tile_set = new TileSet();
}

TiledMap::~TiledMap()
{
	if (_tile_set)
		delete _tile_set;
}

void TiledMap::tile_at(uint16_t x, uint16_t y, uint16_t tile_type_id)
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

void TiledMap::render(Graphics* ptr_graphics, Rect viewport)
{	
	uint16_t top_left_tile_x = (_camera_x / MAP_WIDTH);
	uint16_t top_left_tile_y = (_camera_y / MAP_HEIGHT);	

	uint16_t screen_left_offset = 6;
	uint16_t screen_top_offset = 6;

	Rect source_rect;
	source_rect.x = 0;
	source_rect.y = 0;
	source_rect.w = TILE_WIDTH;
	source_rect.h = TILE_HEIGHT;

	int number_of_rows_to_draw = viewport.h / TILE_HEIGHT;
	int number_of_cols_to_draw = viewport.w / TILE_WIDTH;

	for (int row = top_left_tile_y; row < number_of_rows_to_draw; row++)
	{
		for (int col = top_left_tile_x; col < number_of_cols_to_draw; col++)
		{
			uint16_t tile_id_to_render = _map[col][row];
			Tile* tile_to_render = _tile_set->tile(tile_id_to_render);
			uint32_t render_x = (col * TILE_WIDTH) + screen_left_offset;
			uint32_t render_y = (row * TILE_HEIGHT) + screen_top_offset;
			ptr_graphics->render(tile_to_render->texture(), render_x, render_y, &source_rect, FLIP_NONE, 0);
		}
	}
}
