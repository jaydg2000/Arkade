#pragma once
#include <memory>
#include <queue>
#include <list>
#include <SDL.h>
#include "Sprite.h"

using namespace std;

namespace arkade {

	class SpritePool {
	public:
		SpritePool();
		~SpritePool();

		void									add(Sprite* sprite);
		Sprite*									obtain();
		void									release(Sprite*);
		void									release_deferred(Sprite*);
		void									release_all();
		void									flush();

		list<Sprite*>*							get_sprite_list();

		template<typename Functor>
		void									for_each(Functor functor) {
			for (Sprite* sprite : m_allocated_sprites)
			{
				functor(sprite);
			}
		}

	private:
		queue<Sprite*>							m_available_sprites;
		list<Sprite*>							m_allocated_sprites;
		list<Sprite*>							m_deferred_released_sprites;
	};

}