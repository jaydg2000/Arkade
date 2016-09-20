#pragma once

#include <list>
#include <Sprite.h>
#include <ForwardAnimator.h>
#include "PredatorSprite.h"
#include "CoinSprite.h"

using namespace arkade;

#define ITEM_SHARK 1
#define ITEM_TOOTHY_FISH_1 5
#define ITEM_TOOTHY_FISH_2 6
#define ITEM_TOOTHY_FISH_3 7
#define ITEM_BUG_1 20
#define ITEM_BUG_2 21
#define ITEM_BUG_3 22
#define ITEM_COIN 30
#define ITEM_CRAB 31
#define ITEM_BIRD 32

class SceneRepository
{
public:
	SceneRepository(const char* filename);
	~SceneRepository();

	list<Sprite*>			load_bad_fish();
	list<Sprite*>			load_rewards();
	list<Sprite*>			load_coins();
	void					reload_fish();

private:
	const char*				m_psz_filename;
	list<Sprite*>			m_list_bad_fish_sprites;
	list<Sprite*>			m_list_rewards_sprites;
	list<Sprite*>			m_list_coin_sprites;

	void					read_file(const char* filename);
	Sprite*					make_predator(int type, int x, int y);
	Sprite*					make_reward(int type, int x, int y);
	Sprite*					make_coin(int type, int x, int y);
};

