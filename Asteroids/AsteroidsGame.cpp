#include "AsteroidsGame.h"
#include "Asteroids.h"

AsteroidsGame::AsteroidsGame()
{
	GameAttributes attr;
	attr.full_screen = false;
	attr.hide_cursor = true;
	attr.width = RES_WIDTH;
	attr.height = RES_HEIGHT;

	initialize(attr);
}


AsteroidsGame::~AsteroidsGame()
{
}

void AsteroidsGame::on_setup() {
	//Graphics::instance()->visible_bounding_box(true);
	add_level(&m_level_1);
}

void AsteroidsGame::on_cleanup() {

}