#include "FishGame.h"
#include <Random.h>
#include "Geometry.h"

int32_t FishGame::res_width = SCREEN_WIDTH;
int32_t FishGame::res_height = SCREEN_HEIGHT;


FishGame::FishGame()
{
	GameAttributes attr;
	attr.full_screen = false;
	attr.hide_cursor = false;
	attr.width = FishGame::res_width;
	attr.height = FishGame::res_height;

	initialize(attr);
	Random::seed();
}

FishGame::~FishGame()
{
}

void FishGame::on_setup() {
	m_ptr_level1 = new Level1();
	add_level(m_ptr_level1);
}

void FishGame::on_cleanup() {
	delete m_ptr_level1;
}