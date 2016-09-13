#pragma once
#include <SDL.h>
#include <list>
#include "Graphics.h"
#include "Sprite.h"
#include "SpritePool.h"
#include "TextureCache.h"
#include "Audio.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace arkade {

	class Scene : public MessageSink {
	public:
		Scene();
		~Scene();

		void							run();
		void							stop();
		void							register_sprite(Sprite* ptr_sprite);
		void							unregister_sprite(Sprite* ptr_sprite);
		void							register_sprite_pool(SpritePool* ptr_sprite_pool);

	protected:
		virtual void					on_setup();
		virtual void					on_begin();
		virtual void					on_check_keyboard_input(Keyboard* keyboard);
		virtual void					on_mouse_button(uint32_t button_event_type);
		virtual void					on_update();
		virtual void					on_render(Graphics* ptr_graphics);
		virtual void					on_end();
		virtual void					on_cleanup();
		virtual void					on_detect_collisions();
		virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

	private:
		bool							m_scene_is_ended;
		list<Sprite*>					m_sprite_list;

		void							check_mouse_input();
		void							setup_sprites();
		void							cleanup_sprites();
		void							update_sprites();
		void							handle_messages();
	};
}