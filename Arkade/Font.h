#pragma once
#include "ArkadeTypes.h"

namespace arkade {

	// supports ascii characters 32 through 126 inclusive.
	class Font
	{
	public:
		Font(const char* texture_file_name, Size cell_size);
		~Font();

		Rect*			source_rect_for_character(char c);
		Texture*		texture();
		Size*			cell_size();

	private:
		Size			m_cell_size;
		Rect			m_source_rect;
		Texture*		m_ptr_texture;

	};

}