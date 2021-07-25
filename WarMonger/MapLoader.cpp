#include "MapLoader.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <filesystem>

using namespace std;

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}

TiledMap* MapLoader::load_map(const char* psz_filename)
{
    TiledMap* ptr_map = new TiledMap();
    int buffer_size = (MAP_WIDTH * MAP_HEIGHT) * sizeof(int16_t);
    int tiles_per_row = MAP_WIDTH;
    char* buffer = new char[buffer_size] {0};

    ifstream file(psz_filename, ios::in | ios::binary);
    file.read(buffer, buffer_size);
    
    int buff_pos = 0;
    uint16_t map_col = 0;
    uint16_t map_row = 0;
    while (buff_pos < buffer_size)
    {        
        unsigned char low_byte = buffer[buff_pos];
        unsigned char high_byte = buffer[buff_pos+1];
        uint16_t tile_type_id = low_byte | (high_byte << 8);

        buff_pos += 2;

        ptr_map->tile_at(map_col, map_row, tile_type_id);
        if (++map_col >= tiles_per_row)
        {
            map_col = 0;
            map_row++;
        }
    }
    file.close();
    return ptr_map;
}

void MapLoader::save_map(const char* psz_filename, TiledMap* map)
{
    int buffer_size = (MAP_WIDTH * MAP_HEIGHT) * sizeof(int16_t);
    char* buffer = new char[buffer_size];
    uint32_t buff_pos = 0;
    for (int row = 0; row < MAP_HEIGHT; row++)
    {
        for (int col = 0; col < MAP_WIDTH; col++)
        {
            uint16_t tile_type_id = map->tile_at(col, row);
            char low_byte = 0xFF & tile_type_id;
            char high_byte = (0xFF << 8) & tile_type_id;

            buffer[buff_pos++] = low_byte;
            buffer[buff_pos++] = high_byte;
        }
    }

    ofstream file(psz_filename, ios::out | ios::binary);
    file.write(buffer, buffer_size);
    file.close();
}

void MapLoader::get_all_maps(vector<const char*>* maps)
{
    for (const auto& entry : filesystem::directory_iterator("maps/"))
    {
        auto filename = entry.path().filename().string();
        char* cname = new char[filename.length()+1];
        strcpy_s(cname, filename.length()+1, filename.c_str());
        maps->push_back(cname);
    }    
}
