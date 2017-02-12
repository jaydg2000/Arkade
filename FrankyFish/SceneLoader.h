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
#include "BoulderSprite.h"
#include "SpikeSprite.h"
#include "HeartSprite.h"

#define ITEM_SHARK 1
#define ITEM_TOOTHY_FISH_1 5
#define ITEM_TOOTHY_FISH_2 6
#define ITEM_TOOTHY_FISH_3 7
#define ITEM_JELLY_FISH 8
#define ITEM_BOULDER 9
#define ITEM_SPIKE 10
#define ITEM_BUG_1 20
#define ITEM_BUG_2 21
#define ITEM_BUG_3 22
#define ITEM_COIN 30
#define ITEM_HEART 31

using namespace arkade;

class SceneLoader
{
public:
	SceneLoader();
	~SceneLoader();

	list<Sprite*>			load_gameitems();

private:
	const char*				m_psz_filename;
	list<Sprite*>			m_list_gamesprites;

	void					read_file();
	void					clear_gameitems();
	Sprite*					make_gamesprite(int type, int x, int y);
};

