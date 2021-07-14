#include "WarMongerGame.h"
#include "WarMonger_Main.h"
#include "SceneWar.h"
#include "SceneMainMenu.h"

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
}

void WarMongerGame::on_cleanup() {
}

void WarMongerGame::run_no_pipeline()
{
	SceneWar scene;
	SceneMainMenu mainMenu;
	
	mainMenu.run();
}
