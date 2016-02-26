#pragma once
#include "Scene.h"
#include <queue>

using namespace std;

namespace arkade {

	class Level {
	public:
		Level();
		~Level();

		void						run();
		void						stop();
		void						add_scene(Scene* scene);

	protected:
		virtual void				on_setup();
		virtual void				on_begin();
		virtual void				on_end();
		virtual void				on_cleanup();

	private:
		bool						m_level_is_ended;
		queue<Scene*>				m_scenes;

		void						run_scene();
	};

}