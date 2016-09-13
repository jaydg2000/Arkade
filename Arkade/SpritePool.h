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

		list<Sprite*>*							get_sprite_list();

		template<typename Functor>
		void									for_each(Functor functor) {
			for each (Sprite* sprite in m_allocated_sprites)
			{
				functor(sprite);
			}
		}

	private:
		queue<Sprite*>							m_available_sprites;
		list<Sprite*>							m_allocated_sprites;
	};

}