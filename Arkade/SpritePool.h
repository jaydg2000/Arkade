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

	private:
		queue<Sprite*>							m_available_sprites;
		list<Sprite*>							m_allocated_sprites;
	};

}