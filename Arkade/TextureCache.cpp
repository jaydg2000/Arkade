#include "TextureCache.h"

namespace arkade {

	TextureCache* TextureCache::m_ptr_instance = nullptr;

	TextureCache::TextureCache()
	{
	}


	TextureCache::~TextureCache()
	{
	}

	TextureCache* TextureCache::instance() {
		if (!m_ptr_instance)
			m_ptr_instance = new TextureCache();
		return m_ptr_instance;
	}

	Texture* TextureCache::obtain(const char* name) {
		if (m_texture_map.empty() || m_texture_map.count(name)<1) {
			SDL_Texture* ptr_texture(Graphics::instance()->load_texture(name));
			auto pair = std::make_pair(name, ptr_texture);
			m_texture_map.insert(pair);
		}

		return m_texture_map.at(name);
	}

	void TextureCache::push(const char* name, RGB rgb) {
		Texture* ptr_texture = Graphics::instance()->load_texture(name, rgb);
		auto pair = std::make_pair(name, ptr_texture);
		m_texture_map.insert(pair);
	}
}