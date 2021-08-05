#include "GameState.h"
#include "MapLoader.h"

GameState::GameState()
{
	_players = new vector<Player*>();
	_cities = new vector<City*>();
	_current_player_index = 0;
}

GameState::~GameState()
{
	for (Player* p : *_players)
	{
		delete p;
	}
	delete _players;
}

void GameState::add_player(Player* player)
{
	_players->push_back(player);
}

void GameState::map(TiledMap* map)
{
	_map = map;
	_load_cities();
}

TiledMap* GameState::map()
{
	return _map;
}

void GameState::select_next_player()
{	
	if (++_current_player_index >= _players->size())
		_current_player_index = 0;
}

void GameState::select_next_unit()
{
	_current_unit_index++;
}

Player* GameState::current_player()
{
	return _players->at(_current_player_index);
}

Unit* GameState::current_unit()
{
	if (_current_unit_index >= current_player()->units()->size())
		return nullptr;
		
	return current_player()->units()->at(_current_unit_index);
}

vector<City*>* GameState::cities()
{
	return _cities;
}

vector<Player*>* GameState::players()
{
	return _players;
}

void GameState::_load_cities()
{
	_cities->clear();
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			if (_map->tile_at_xy(x,y) == TILE_CITY_1)
			{
				City* city = new City(x,y);
			}
		}
	}
}
