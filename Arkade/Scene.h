#pragma once
#include <SDL.h>
#include <list>
#include "Graphics.h"
#include "Sprite.h"
#include "SpritePool.h"
#include "TextureCache.h"
#include "Audio.h"
#include "InputManager.h"
#include "Timer.h"

namespace arkade {

	class Scene : public MessageSink {
	public:
		Scene();
		~Scene();

		bool							run();
		void							stop();
		void							end();
		void							disable_sprite_updates();
		void							enable_sprite_updates();
		void							pause();
		void							resume();
		bool							is_paused();
		void							register_sprite(Sprite* ptr_sprite);
		void							unregister_sprite(Sprite* ptr_sprite);
		void							register_sprite_pool(SpritePool* ptr_sprite_pool);
		void							millis_per_frame(uint32_t millis);
		void							type(uint32_t type);
		uint32_t						type();		
		void							show_mouse();
		void							hide_mouse();

	protected:
		virtual void					on_setup();
		virtual void					on_begin();
		virtual void					on_check_input(InputManager* keyboard);
		virtual void					on_update();
		virtual void					on_render(Graphics* ptr_graphics);
		virtual void					on_end();
		virtual void					on_cleanup();
		virtual void					on_detect_collisions();
		virtual void					on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data);

	private:
		uint32_t						m_type;
		uint32_t						m_millis_per_frame;
		bool							m_is_updating_sprites;
		bool							m_scene_is_ended;
		bool							m_game_is_ended;
		bool							m_is_paused;
		list<Sprite*>					m_sprite_list;
		Timer							m_frame_timer;

		void							setup_sprites();
		void							cleanup_sprites();
		void							update_sprites();
		void							handle_messages();
	};
}