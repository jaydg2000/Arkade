#pragma once
#include <SDL.h>

namespace arkade {

	class Size {

	public:


		Size();
		Size(uint32_t width, uint32_t height);
		~Size();

		static Size		NONE;

		uint32_t		width();
		void			width(uint32_t);
		uint32_t		height();
		void			height(uint32_t);

	private:

		uint32_t		m_width;
		uint32_t		m_height;

	};

}
