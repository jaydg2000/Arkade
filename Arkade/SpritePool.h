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
		SpritePool(uint32_t initial_size);
		~SpritePool();

		Sprite*									obtain();
		void									release(Sprite*);

		//template<typename F>
		//void									for_each(F op);
		list<Sprite*>*							get_sprite_list();

	private:
		queue<Sprite*>							m_available_sprites;
		list<Sprite*>							m_allocated_sprites;

		void									expand_pool();
	};

}