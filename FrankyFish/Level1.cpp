#include "Level1.h"
#include "SceneFrankysFirstSwim.h"

Level1::Level1() {
}


Level1::~Level1() {
}

void Level1::on_setup() {
	m_ptr_scene_franky_first_swim = new SceneFrankysFirstSwim();
	add_scene(m_ptr_scene_franky_first_swim);
}