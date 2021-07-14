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
		m_use_screen_positioning = false;
	}

	Image::Image(Texture* ptr_texture, Size texture_size, float x, float y, bool use_screen_positioning)
	{
		m_ptr_texture = ptr_texture;
		m_x = x;
		m_y = y;
		m_size = texture_size;
		m_rotation = 0.0f;

		m_source_rect.x = 0;
		m_source_rect.y = 0;
		m_source_rect.w = texture_size.x;
		m_source_rect.h = texture_size.y;

		m_destination_rect.w = texture_size.x;
		m_destination_rect.h = texture_size.y;

		m_flip = FLIP_NONE;
		m_use_screen_positioning = use_screen_positioning;
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

	void Image::source_rect(Rect& rect) {
		m_source_rect.x = rect.x;
		m_source_rect.y = rect.y;
		m_source_rect.w = rect.w;
		m_source_rect.h = rect.h;
	}

	Rect * Image::destination_rect()
	{
		m_destination_rect.x = (int)m_x;
		m_destination_rect.y = (int)m_y;
		return &m_destination_rect;
	}

	void Image::destination_rect(Rect& rect) {
		m_destination_rect.x = rect.x;
		m_destination_rect.y = rect.y;
		m_destination_rect.w = rect.w;
		m_destination_rect.h = rect.h;
	}

	bool Image::use_screen_positioning() {
		return m_use_screen_positioning;
	}

	void Image::use_screen_positioning(bool enabled) {
		m_use_screen_positioning = enabled;
	}
}