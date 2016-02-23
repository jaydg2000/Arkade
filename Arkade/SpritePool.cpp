#include "SpritePool.h"

namespace arkade {

	SpritePool::SpritePool(uint32_t initial_size)
	{
		while (initial_size-- > 0) {
			expand_pool();
		}
	}

	SpritePool::~SpritePool()
	{
	}

	Sprite& SpritePool::obtain() {
		if (m_available_sprites.empty()) {
			expand_pool();
		}
		Sprite* ptr_sprite = m_available_sprites.front();
		return *ptr_sprite;
	}

	void SpritePool::expand_pool() {
		m_allocated_sprites.push_back(new Sprite());
	}
}