#pragma once
#include "RewardSprite.h"

class CoinSprite : public RewardSprite
{
public:
	CoinSprite();
	~CoinSprite();

	void					on_set_stage() override;
};

