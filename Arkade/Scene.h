#pragma once
#include <SDL.h>
#include <list>
#include "Graphics.h"
#include "Sprite.h"
#include "SpritePool.h"
#include "TextureCache.h"
#include "Audio.h"

namespace arkade {

	class Scene {
	public:
		Scene();
		~Scene();

		void							run();
		void							stop();
		void							register_sprite(Sprite* ptr_sprite);
		void							register_sprite_pool(SpritePool* ptr_sprite_pool);

	protected:
		virtual void					on_setup();
		virtual void					on_begin();
		virtual void					on_keyboard_input();
		virtual void					on_mouse_input();
		virtual void					on_update();
		virtual void					on_render(Graphics* ptr_graphics);
		virtual void					on_end();
		virtual void					on_cleanup();
		virtual void					on_detect_collisions();

	private:
		bool							m_scene_is_ended;
		list<Sprite*>					m_sprite_list;

		void							check_keyboard_input();
		void							check_mouse_input();
		void							setup_sprites();
		void							cleanup_sprites();
		void							update_sprites();
		void							handle_messages();
	};
}