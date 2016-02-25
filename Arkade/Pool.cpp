#include "Pool.h"

namespace arkade {
	template<class T>
	Pool::Pool()
	{
	}

	template<class T>
	Pool::~Pool()
	{
	}

	template<class T>
	T* Pool::obtain() {
		if (m_available.empty()) {
			expand_pool();
		}
		T* ptr = m_available.front();
		return ptr_sprite;
	}

	template<class T>
	void Pool::release(T* ptr) {		
		m_available.push(ptr);
		m_allocated.remove(ptr);
	}

	template<class T>
	void Pool::expand_pool() {
		m_allocated.push_back(new T());
	}

	template<class T, typename F>
	void Pool::for_each(F op) {
		for (T* obj : (*m_allocated)) {
			op(obj);
		}
	}

}