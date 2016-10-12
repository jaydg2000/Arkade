#pragma once

#include <list>
#include <Sprite.h>
#include <ForwardAnimator.h>
#include "SharkSprite.h"
#include "ToothyFishOneSprite.h"
#include "ToothyFishTwoSprite.h"
#include "ToothyFishThreeSprite.h"
#include "BirdSprite.h"
#include "CoinSprite.h"
#include "BugOneSprite.h"
#include "BugTwoSprite.h"
#include "BugThreeSprite.h"
#include "JellyFishSprite.h"

using namespace arkade;

#define ITEM_SHARK 1
#define ITEM_TOOTHY_FISH_1 5
#define ITEM_TOOTHY_FISH_2 6
#define ITEM_TOOTHY_FISH_3 7
#define ITEM_JELLY_FISH 8
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

	list<Sprite*>			load_gameitems();

private:
	const char*				m_psz_filename;
	list<Sprite*>			m_list_gamesprites;

	void					read_file();
	void					clear_gameitems();
	Sprite*					make_gamesprite(int type, int x, int y);
};

