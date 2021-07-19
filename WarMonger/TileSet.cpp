#include "TileSet.h"
#include <TextureCache.h>

#define TILE_WATER_1    101
#define TILE_LAND_1     111
#define TILE_FOREST_1   121
#define TILE_MOUNTAIN_1 131
#define TILE_RIVER_1    141

TileSet::TileSet()
{
    _tiles.insert(make_pair(TILE_WATER_1, new Tile(TILE_WATER_1, TextureCache::instance()->obtain("res/tile_water.png"))));
    _tiles.insert(make_pair(TILE_LAND_1, new Tile(TILE_LAND_1, TextureCache::instance()->obtain("res/tile_land.png"))));
    _tiles.insert(make_pair(TILE_FOREST_1, new Tile(TILE_FOREST_1, TextureCache::instance()->obtain("res/tile_forest.png"))));
    _tiles.insert(make_pair(TILE_MOUNTAIN_1, new Tile(TILE_MOUNTAIN_1, TextureCache::instance()->obtain("res/tile_mountain.png"))));
    _tiles.insert(make_pair(TILE_RIVER_1, new Tile(TILE_RIVER_1, TextureCache::instance()->obtain("res/tile_river.png"))));
}

TileSet::~TileSet()
{
}

Tile* TileSet::tile(uint16_t tile_id)
{
    return _tiles[tile_id];
}
