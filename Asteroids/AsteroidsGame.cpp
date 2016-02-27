#include "AsteroidsGame.h"

AsteroidsGame::AsteroidsGame()
{
	GameAttributes attr;	
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