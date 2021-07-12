#include "WarMongerGame.h"
#include "WarMonger_Main.h"

WarMongerGame::WarMongerGame() {
	GameAttributes attr;
	attr.full_screen = false;
	attr.hide_cursor = true;
	attr.width = RES_WIDTH;
	attr.height = RES_HEIGHT;

	initialize(attr);
}

WarMongerGame::~WarMongerGame() {	
}

void WarMongerGame::on_setup() {
	_level_war = new LevelWar();
	add_level(_level_war);
}

void WarMongerGame::on_cleanup() {
	delete _level_war;
}