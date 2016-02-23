#include "Game.h"

namespace arkade {

	Game::Game()
	{
		m_game_is_ended = false;
	}


	Game::~Game()
	{
	}

	void Game::run() {
		on_setup();
		while (!m_game_is_ended) {
			run_level();
		}
		on_cleanup();
	}

	void Game::stop() {
		m_game_is_ended = true;
	}

	void Game::add_level(Level* level) {
		m_levels.push(level);
	}

	void Game::run_level() {
		Level* level = m_levels.front();
		m_levels.pop();
		level->run();
		if (m_levels.empty())
			stop();
	}
}