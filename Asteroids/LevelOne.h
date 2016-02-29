#pragma once
#include <Level.h>
#include "LevelOneGameScene.h"

using namespace arkade;

class LevelOne :
	public Level {
public:
	LevelOne();
	~LevelOne();

	virtual void on_setup();
	virtual void on_begin();
	virtual void on_cleanup();

private:
	LevelOneGameScene*			m_game_scene;
};

