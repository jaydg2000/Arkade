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

	Sprite* SpritePool::obtain() {
		if (m_available_sprites.empty()) {
			expand_pool();
		}
		Sprite* ptr_sprite = m_available_sprites.front();
		ptr_sprite->on_pool_obtain();
		return ptr_sprite;
	}

	void SpritePool::release(Sprite* ptr_sprite) {
		ptr_sprite->on_pool_release();
		m_available_sprites.push(ptr_sprite);
		m_allocated_sprites.remove(ptr_sprite);
	}

	void SpritePool::expand_pool() {
		m_allocated_sprites.push_back(new Sprite());
	}

	template<typename F>
	void SpritePool::for_each(F op) {
		for(Sprite* sprite : (*m_allocated_sprites)) {
			op(sprite);
		}
	}
}