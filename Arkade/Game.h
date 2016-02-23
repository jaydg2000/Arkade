#pragma once
#include "Level.h"
#include <queue>

using namespace std;

namespace arkade {

	class Game {
	public:
		Game();
		~Game();

		void			run();
		void			stop();
		void			add_level(Level*);

	protected:
		virtual void	on_setup() = 0;
		virtual void	on_cleanup() = 0;

	private:
		queue<Level*>	m_levels;
		bool			m_game_is_ended;
	
		void			run_level();
	};

}