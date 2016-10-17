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
		void						millis_per_frame(uint32_t millis);

	protected:
		virtual void				on_setup();
		virtual void				on_begin();
		virtual void				on_end();
		virtual void				on_cleanup();
		virtual void				on_begin_scene(Scene* scene);
		virtual void				on_end_scene(Scene* scene);

	private:
		uint32_t					m_millis_per_frame;
		bool						m_level_is_ended;
		queue<Scene*>				m_scenes;

		void						run_scene();
	};

}