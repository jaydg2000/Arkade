#pragma once
#include "Sprite.h"
#include "Scene.h"

namespace arkade {

	class SpriteBehavior {
	public:
		SpriteBehavior();
		~SpriteBehavior();

		void					on_setup();
		void					on_cleanup();
		void					on_keyboard();
		void					on_mouse();
		void					on_collision(const Sprite& sprite_collided_with);
		void					on_update(Scene* ptr_current_scene);
		virtual void			on_pre_render();
		virtual void			on_post_render();

	};

}