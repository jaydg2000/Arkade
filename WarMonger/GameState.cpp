#include "GameState.h"
#include "MapLoader.h"

GameState::GameState()
{
	_players = new vector<Player*>();
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
}

TiledMap* GameState::map()
{
	return _map;
}
