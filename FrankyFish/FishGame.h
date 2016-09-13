#pragma once
#include <Game.h>
#include "Level1.h"

using namespace arkade;

class FishGame : public Game
{
public:
	FishGame();
	~FishGame();

	static int32_t res_width;
	static int32_t res_height;

protected:
	virtual void					on_setup();
	virtual void					on_cleanup();

private:
	Level*							m_ptr_level1;
};

