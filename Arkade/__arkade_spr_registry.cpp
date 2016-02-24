#include "__arkade_spr_registry.h"

namespace arkade {

	__arkade_spr_registry::__arkade_spr_registry()
	{
	}


	__arkade_spr_registry::~__arkade_spr_registry()
	{
	}

	__arkade_spr_registry* __arkade_spr_registry::instance() {
		if (!m_ptr_instance)
			m_ptr_instance = new __arkade_spr_registry();
		return m_ptr_instance;
	}

	void __arkade_spr_registry::add(Sprite* sprite) {
		(*m_ptr_sprites).push_front(sprite);
		(*m_ptr_sprites).sort(__arkade_spr_compare);
	}

	void __arkade_spr_registry::clear() {
		(*m_ptr_sprites).clear();
	}

	template<typename F>
	void __arkade_spr_registry::for_each(F op) {
		for(Sprite* sprite : (*m_ptr_sprites)) {
			op(sprite);
	}
}