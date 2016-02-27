#pragma once
#include <Game.h>

using namespace arkade;

class AsteroidsGame : public Game {
public:
	AsteroidsGame();
	~AsteroidsGame();

protected:
	virtual void			on_setup();
	virtual void			on_cleanup();

private:
	Level					m_level_1;
};

