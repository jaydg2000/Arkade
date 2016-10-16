#include "SpritePool.h"

namespace arkade {

	SpritePool::SpritePool()
	{		
	}

	SpritePool::~SpritePool()
	{
	}

	void SpritePool::add(Sprite* sprite) {
		m_available_sprites.push(sprite);
	}

	Sprite* SpritePool::obtain() {
		if (m_available_sprites.empty())
			return nullptr;
		Sprite* ptr_sprite = m_available_sprites.front();
		m_allocated_sprites.push_back(ptr_sprite);
		m_available_sprites.pop();
		ptr_sprite->on_pool_obtain();
		return ptr_sprite;
	}

	void SpritePool::release(Sprite* ptr_sprite) {
		ptr_sprite->on_pool_release();
		m_available_sprites.push(ptr_sprite);
		m_allocated_sprites.remove(ptr_sprite);
	}

	void SpritePool::release_all() {
		for each (Sprite* ptr_sprite in m_allocated_sprites) {
			ptr_sprite->on_pool_release();
			m_available_sprites.push(ptr_sprite);
		}
		m_allocated_sprites.clear();
	}

	list<Sprite*>* SpritePool::get_sprite_list() {
		return &m_allocated_sprites;
	}
}