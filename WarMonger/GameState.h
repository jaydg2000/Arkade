#pragma once
#include <vector>
#include "Player.h"
#include "TiledMap.h"
#include "City.h"

using namespace std;

class GameState
{
public:
	GameState();
	~GameState();

	void								add_player(Player* player);
	void								map(TiledMap* map);
	TiledMap*							map();
	void								select_next_player();
	void								select_next_unit();
	Player*								current_player();
	Unit*								current_unit();
	vector<City*>*						cities();
	vector<Player*>*					players();

private:
	vector<Player*>*					_players;
	vector<City*>*						_cities;
	TiledMap*							_map;
	uint32_t							_current_player_index;
	uint32_t							_current_unit_index;

	void								_load_cities();
};

