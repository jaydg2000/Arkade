#include "TiledMap.h"
#include <Camera.h>

TiledMap::TiledMap()
{	
	//_camera_x = _camera_y = 0;
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

uint32_t TiledMap::screen_to_map_x(uint32_t screen_x)
{
	uint32_t first_cell_x = Camera::instance()->position_x() / TILE_WIDTH;
	uint32_t offset = (screen_x / TILE_WIDTH);
	return first_cell_x + offset;
}

uint32_t TiledMap::screen_to_map_y(uint32_t screen_y)
{
	uint32_t first_cell_y = Camera::instance()->position_y() / TILE_HEIGHT;
	uint32_t offset = (screen_y / TILE_HEIGHT);
	return first_cell_y + offset;
}

uint32_t TiledMap::map_to_screen_x(uint32_t map_x)
{
	return (map_x * TILE_WIDTH) - Camera::instance()->position_x();
}

uint32_t TiledMap::map_to_screen_y(uint32_t map_y)
{
	return (map_y * TILE_HEIGHT) - Camera::instance()->position_y();
}

void TiledMap::render(Graphics* ptr_graphics, Rect viewport)
{	
	Camera* camera = Camera::instance();
	uint32_t camera_x = camera->position_x();
	uint32_t camera_y = camera->position_y();
	uint16_t top_left_tile_x = (camera_x / TILE_WIDTH);
	uint16_t top_left_tile_y = (camera_y / TILE_HEIGHT);	

	uint16_t screen_left_offset = 6;
	uint16_t screen_top_offset = 6;

	Rect source_rect;
	source_rect.x = 0;
	source_rect.y = 0;
	source_rect.w = TILE_WIDTH;
	source_rect.h = TILE_HEIGHT;

	int number_of_rows_to_draw = viewport.h / TILE_HEIGHT;
	int number_of_cols_to_draw = viewport.w / TILE_WIDTH;

	for (int row_index = 0; row_index < number_of_rows_to_draw; row_index++)
	{
		for (int col_index = 0; col_index < number_of_cols_to_draw; col_index++)
		{
			int col = top_left_tile_x + col_index;
			int row = top_left_tile_y + row_index;
			uint16_t tile_id_to_render = _map[col][row];
			Tile* tile_to_render = _tile_set->tile(tile_id_to_render);
			if (tile_to_render == nullptr)
				continue;
			uint32_t screen_x = (col_index * TILE_WIDTH) + screen_left_offset;
			uint32_t screen_y = (row_index * TILE_HEIGHT) + screen_top_offset;
			uint32_t render_x = camera_x + screen_x;
			uint32_t render_y = camera_y + screen_y;
			ptr_graphics->render(tile_to_render->texture(), render_x, render_y, &source_rect, FLIP_NONE, 0);
		}
	}
}

void TiledMap::fill(Tile* tile)
{
	for (int x = 0; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			_map[x][y] = tile->tile_type();
		}
	}
}
