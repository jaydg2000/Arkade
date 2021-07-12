#include "LevelWar.h"

LevelWar::LevelWar() {}
LevelWar::~LevelWar() {}

void LevelWar::on_setup() {
	_scene = new SceneWar();
}

void LevelWar::on_begin() {
	add_scene(_scene);
}

void LevelWar::on_cleanup() {
	delete _scene;
}