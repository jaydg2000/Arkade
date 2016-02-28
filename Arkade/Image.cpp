#include "Image.h"
#include "TextureCache.h"

namespace arkade {

	Image::Image(const char* filename, Size texture_size, float x, float y)
	{
		m_ptr_texture = TextureCache::instance()->obtain(filename);
		m_size = texture_size;
		m_x = x;
		m_y = y;

		m_rotation = 0.0f;

		m_source_rect.x = 0;
		m_source_rect.y = 0;
		m_source_rect.w = texture_size.x;
		m_source_rect.h = texture_size.y;

		m_destination_rect.w = texture_size.x;
		m_destination_rect.h = texture_size.y;

		m_flip = FLIP_NONE;
	}

	Image::~Image()
	{
	}

	Texture * arkade::Image::texture()
	{
		return m_ptr_texture;
	}

	float Image::x()
	{
		return m_x;
	}

	float Image::y()
	{
		return m_y;
	}

	void Image::x(float x)
	{
		m_x = x;
	}

	void Image::y(float y)
	{
		m_y = y;
	}

	float Image::rotation()
	{
		return m_rotation;
	}

	void Image::rotation(float rotation)
	{
		m_rotation = rotation;
	}

	Flip Image::flip()
	{
		return m_flip;
	}

	void Image::flip(Flip flip)
	{
		m_flip = flip;
	}

	Rect * Image::source_rect()
	{
		return &m_source_rect;
	}

	Rect * Image::destination_rect()
	{
		m_destination_rect.x = m_x;
		m_destination_rect.y = m_y;
		return &m_destination_rect;
	}

}