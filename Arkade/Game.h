#pragma once
#include <queue>
#include "Level.h"
#include "GameAttributes.h"

using namespace std;

namespace arkade {

	class Game {
	public:
		Game();
		~Game();

		void			initialize(GameAttributes& game_attributes);
		void			run();
		virtual void	run_no_pipeline();
		void			stop();
		void			add_level(Level*);		

	protected:
		virtual void	on_setup() = 0;
		virtual void	on_cleanup() = 0;

	private:		
		queue<Level*>	m_levels;
		bool			m_game_is_ended;
		uint32_t		m_millis_per_frame;

		void			run_level();
	};

}
