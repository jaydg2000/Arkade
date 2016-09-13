#include "FishGame.h"
#include <Random.h>

int32_t FishGame::res_width = 720;
int32_t FishGame::res_height = 1280;


FishGame::FishGame()
{
	GameAttributes attr;
	attr.full_screen = false;
	attr.hide_cursor = true;
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