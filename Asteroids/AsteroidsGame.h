#pragma once
#include <Game.h>
#include "LevelOne.h"

using namespace arkade;

class AsteroidsGame : public Game {
public:
	AsteroidsGame();
	~AsteroidsGame();

protected:
	virtual void			on_setup();
	virtual void			on_cleanup();

private:
	LevelOne				m_level_1;
};

