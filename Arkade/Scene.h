#pragma once
#include <SDL.h>

namespace arkade {

	class Scene {
	public:
		Scene();
		~Scene();

		void				run();
		void				stop();

	protected:
		virtual void		on_setup();
		virtual void		on_begin();
		virtual void		on_loop();
		virtual void		on_end();
		virtual void		on_cleanup();

		void				check_keybaord_input();
		void				check_mouse_input();
		void				check_sprite_collisions();
		void				send_messages();
		void				update_sprites();
		void				render_all();
	private:
		bool				m_scene_is_ended;
	};

}