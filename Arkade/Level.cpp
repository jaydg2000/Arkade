#include "Level.h"

namespace arkade {

	Level::Level()
	{
		m_level_is_ended = false;
	}


	Level::~Level()
	{
	}

	void Level::millis_per_frame(uint32_t millis) {
		m_millis_per_frame = millis;
	}

	void Level::run() {
		on_setup();
		on_begin();
		while (!m_level_is_ended)
			run_scene();
		on_end();
		on_cleanup();
	}

	void Level::stop() {
		m_level_is_ended = true;
	}

	void Level::add_scene(Scene* scene) {
		scene->millis_per_frame(m_millis_per_frame);
		m_scenes.push(scene);
	}

	void Level::on_setup() {

	}

	void Level::on_begin() {

	}

	void Level::on_end() {

	}

	void Level::on_cleanup() {

	}

	void Level::run_scene() {
		Scene* scene = m_scenes.front();
		m_scenes.pop();
		scene->run();
		if (m_scenes.empty())
			stop();
	}
}