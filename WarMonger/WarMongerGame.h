#pragma once
#include <Game.h>
#include "LevelWar.h"

using namespace arkade;

class WarMongerGame : public Game {
public:
	WarMongerGame();
	~WarMongerGame();

protected:
	virtual void			on_setup();
	virtual void			on_cleanup();

private:
	LevelWar*				_level_war;

};

