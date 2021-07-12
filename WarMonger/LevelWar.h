#pragma once
#include <Level.h>
#include "SceneWar.h"

using namespace arkade;

class LevelWar : public Level
{
public:
	LevelWar();
	~LevelWar();

	virtual void					on_setup();
	virtual void					on_begin();
	virtual void					on_cleanup();

private:
	SceneWar*						_scene;
};

