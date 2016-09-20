#include "stdafx.h"
#include "CoinSprite.h"
#include <Random.h>
#include <ForwardAnimator.h>


CoinSprite::CoinSprite()
	:RewardSprite("res/sprites/sprite_coin.png", make_size(66, 65), 10)
{
	animator(new ForwardAnimator(6, 90));
	animator()->current_frame(Random::rand_int(0, 5));
}


CoinSprite::~CoinSprite()
{
}
