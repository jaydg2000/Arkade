#include "AsteroidsGame.h"
#include "Asteroids.h"

AsteroidsGame::AsteroidsGame()
{
	GameAttributes attr;
	attr.full_screen = true;
	attr.hide_cursor = false;
	attr.width = RES_WIDTH;
	attr.height = RES_HEIGHT;

	initialize(attr);
}


AsteroidsGame::~AsteroidsGame()
{
}

void AsteroidsGame::on_setup() {
	add_level(&m_level_1);
}

void AsteroidsGame::on_cleanup() {

}