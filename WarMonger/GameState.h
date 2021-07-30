#pragma once
#include <vector>
#include "Player.h"
#include "TiledMap.h"

using namespace std;

class GameState
{
public:
	GameState();
	~GameState();

	void								add_player(Player* player);
	void								map(TiledMap* map);
	TiledMap*							map();

private:
	vector<Player*>*					_players;
	TiledMap*							_map;
};

