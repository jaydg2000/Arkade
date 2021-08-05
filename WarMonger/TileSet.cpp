#include "TileSet.h"
#include <TextureCache.h>

TileSet::TileSet()
{
    _tiles.insert(make_pair(TILE_WATER_1, new Tile(TILE_WATER_1, TextureCache::instance()->obtain("res/tile_water.png"))));
    _tiles.insert(make_pair(TILE_LAND_1, new Tile(TILE_LAND_1, TextureCache::instance()->obtain("res/tile_land.png"))));
    _tiles.insert(make_pair(TILE_FOREST_1, new Tile(TILE_FOREST_1, TextureCache::instance()->obtain("res/tile_forest.png"))));
    _tiles.insert(make_pair(TILE_MOUNTAIN_1, new Tile(TILE_MOUNTAIN_1, TextureCache::instance()->obtain("res/tile_mountain.png"))));
    _tiles.insert(make_pair(TILE_RIVER_1, new Tile(TILE_RIVER_1, TextureCache::instance()->obtain("res/tile_river.png"))));
    _tiles.insert(make_pair(TILE_CITY_1, new Tile(TILE_CITY_1, TextureCache::instance()->obtain("res/tile_city.png"))));
}

TileSet::~TileSet()
{
}

Tile* TileSet::tile(uint16_t tile_id)
{
    return _tiles[tile_id];
}

bool TileSet::is_land(uint16_t tile_type_id)
{
    return tile_type_id == TILE_LAND_1;
}

bool TileSet::is_water(uint16_t tile_type_id)
{
    return tile_type_id == TILE_WATER_1;
}

bool TileSet::is_forest(uint16_t tile_type_id)
{
    return tile_type_id == TILE_FOREST_1;
}

bool TileSet::is_mountain(uint16_t tile_type_id)
{
    return tile_type_id == TILE_MOUNTAIN_1;
}

bool TileSet::is_river(uint16_t tile_type_id)
{
    return tile_type_id == TILE_RIVER_1;
}
