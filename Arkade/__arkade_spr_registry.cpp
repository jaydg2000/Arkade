#include "__arkade_spr_registry.h"

namespace arkade {

	__arkade_spr_registry::__arkade_spr_registry()
	{
	}


	__arkade_spr_registry::~__arkade_spr_registry()
	{
	}

	const __arkade_spr_registry& __arkade_spr_registry::instance() {
		if (!m_ptr_instance)
			m_ptr_instance = std::make_unique<__arkade_spr_registry>();
		return *m_ptr_instance;
	}

	forward_list<Sprite*>::iterator __arkade_spr_registry::itr() {
		return (*m_ptr_sprites).begin();
	}

	void __arkade_spr_registry::add(Sprite* sprite) {
		(*m_ptr_sprites).push_front(sprite);
		(*m_ptr_sprites).sort(__arkade_spr_compare);
	}

	void __arkade_spr_registry::clear() {
		(*m_ptr_sprites).clear();
	}
}