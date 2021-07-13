#pragma once
#include <Game.h>

using namespace arkade;

class WarMongerGame : public Game {
public:
	WarMongerGame();
	~WarMongerGame();

	virtual void			run_no_pipeline();

protected:
	virtual void			on_setup();
	virtual void			on_cleanup();


};
