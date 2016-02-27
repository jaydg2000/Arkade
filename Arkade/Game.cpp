#include "Game.h"

namespace arkade {

	Game::Game()
	{
		m_game_is_ended = false;
	}


	Game::~Game()
	{
	}

	void Game::initialize(GameAttributes & game_attributes)
	{
		Graphics::instance()->initialize(
			game_attributes.full_screen,
			game_attributes.width,
			game_attributes.height,
			game_attributes.color_depth,
			game_attributes.psz_caption);

		Audio::instance()->initialize(
			game_attributes.audio_rate,
			game_attributes.audio_format,
			game_attributes.audio_channels,
			game_attributes.audio_buffers);
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
		Graphics::instance()->uninitialize();
		Audio::instance()->uninitialize();
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