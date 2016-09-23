#include "FishGame.h"
#include <Random.h>
#include "Geometry.h"

int32_t FishGame::res_width = WINDOW_WIDTH;
int32_t FishGame::res_height = WINDOW_HEIGHT;


FishGame::FishGame()
{
	GameAttributes attr;
	attr.full_screen = false;
	attr.hide_cursor = false;
	attr.width = WINDOW_WIDTH;
	attr.height = WINDOW_HEIGHT;
	
	attr.use_logical_scale = true;
	attr.logical_width = LOGICAL_WIDTH;
	attr.logical_height = LOGICAL_HEIGHT;

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