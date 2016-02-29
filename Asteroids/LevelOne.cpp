#include "LevelOne.h"



LevelOne::LevelOne()
{
}


LevelOne::~LevelOne()
{
}

void LevelOne::on_setup()
{
	m_game_scene = new LevelOneGameScene();
}

void LevelOne::on_begin() {
	this->add_scene(m_game_scene);
}

void LevelOne::on_cleanup() {
	delete m_game_scene;
}
