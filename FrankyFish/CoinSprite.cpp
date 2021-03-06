#include "CoinSprite.h"
#include <Random.h>
#include <ForwardAnimator.h>


CoinSprite::CoinSprite()
	:RewardSprite("res/sprites/sprite_coin.png", make_size(66, 65), 1)
{
	animator(new ForwardAnimator(6, 50));
	//animator()->current_frame(Random::rand_int(0, 5));
	collision_dim(15,5,35,55);
}


CoinSprite::~CoinSprite()
{
}

void CoinSprite::on_set_stage() {
	animator()->reset();
}