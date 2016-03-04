#include "Font.h"
#include "TextureCache.h"

namespace arkade {

	Font::Font(const char* texture_file_name, Size cell_size)
	{
		m_ptr_texture = TextureCache::instance()->obtain(texture_file_name);
		m_cell_size.x = cell_size.x;
		m_cell_size.y = cell_size.y;

		m_source_rect.y = 0;
		m_source_rect.w = m_cell_size.x;
		m_source_rect.h = m_cell_size.y;

	}


	Font::~Font()
	{
	}

	Rect* Font::source_rect_for_character(char c) {
		m_source_rect.x = ((c - 32) * m_cell_size.x);
		return &m_source_rect;
	}

	Texture* Font::texture() {
		return m_ptr_texture;
	}

	Size* Font::cell_size() {
		return &m_cell_size;
	}
}