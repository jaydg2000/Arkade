#include "Game.h"
#include "Random.h"

namespace arkade {

	Game::Game()
	{		
		m_game_is_ended = false;
		Random::seed();
	}

	Game::~Game()
	{
	}

	void Game::initialize(GameAttributes & game_attributes)
	{

		if (game_attributes.use_logical_scale) {
			Graphics::instance()->initialize(
				game_attributes.full_screen,
				game_attributes.width,
				game_attributes.height,
				game_attributes.color_depth,
				game_attributes.logical_width,
				game_attributes.logical_height,
				game_attributes.psz_caption);
		}
		else {
			Graphics::instance()->initialize(
				game_attributes.full_screen,
				game_attributes.width,
				game_attributes.height,
				game_attributes.color_depth,
				game_attributes.psz_caption);
		}

		Audio::instance()->initialize(
			game_attributes.audio_rate,
			game_attributes.audio_format,
			game_attributes.audio_channels,
			game_attributes.audio_buffers);

		if (game_attributes.hide_cursor)
			SDL_ShowCursor(0);

		m_millis_per_frame = 1000.0f / game_attributes.frame_rate;
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
		if (SDL_ShowCursor(-1) == 0)
			SDL_ShowCursor(1);
	}

	void Game::add_level(Level* level) {
		level->millis_per_frame(m_millis_per_frame);
		m_levels.push(level);
	}

	void Game::run_level() {
		Level* level = m_levels.front();
		m_levels.pop();
		if (!level->run())
			stop();
		if (m_levels.empty())
			stop();
	}
}