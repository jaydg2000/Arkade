#pragma once
#include "Sprite.h"
#include <vector>
#include <queue>
#include <forward_list>

namespace arkade {

	bool __arkade_spr_compare(Sprite* ptr_s1, Sprite* ptr_s2) { return ptr_s1->z_order() < ptr_s2->z_order(); }

	typedef priority_queue<Sprite*, vector<Sprite*>, decltype(__arkade_spr_compare)> __arkade_sprite_queue;

	class __arkade_spr_registry {
	public:
		~__arkade_spr_registry();

		static const __arkade_spr_registry&			instance();

		forward_list<Sprite*>::iterator				itr();
		
		void										add(Sprite* ptr_sprite);
		void										clear();

	private:
		static unique_ptr<__arkade_spr_registry>	m_ptr_instance;
		unique_ptr<forward_list<Sprite*>>			m_ptr_sprites;
		bool										m_is_dirty;

		__arkade_spr_registry();

	};

}