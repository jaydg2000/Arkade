#pragma once
#include <vector>
#include <queue>
#include <forward_list>
#include <memory>
#include "Sprite.h"

namespace arkade {

	bool __arkade_spr_compare(Sprite* ptr_s1, Sprite* ptr_s2) { return ptr_s1->z_order() < ptr_s2->z_order(); }

	typedef priority_queue<Sprite*, vector<Sprite*>, decltype(__arkade_spr_compare)> __arkade_sprite_queue;

	class __arkade_spr_registry {
	public:
		~__arkade_spr_registry();

		static __arkade_spr_registry*				instance();

		template<typename F>
		void										for_each(F op);
		
		void										add(Sprite* ptr_sprite);
		void										clear();

	private:
		static __arkade_spr_registry*				m_ptr_instance;
		unique_ptr<forward_list<Sprite*>>			m_ptr_sprites;
		bool										m_is_dirty;

		__arkade_spr_registry();

	};

}