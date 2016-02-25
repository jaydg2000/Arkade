#pragma once

namespace arkade {

	template<class T>
	class Pool
	{
	public:
		Pool();
		~Pool();

		T*									obtain();
		void								release(T*);

		template<typename F>
		void								for_each(F op);

	private:
		queue<T*>							m_available;
		list<T*>							m_allocated;

		void								expand_pool();

	};

}