#include "TextureCache.h"

namespace arkade {

	TextureCache* TextureCache::m_ptr_instance = nullptr;

	TextureCache::TextureCache()
	{
	}


	TextureCache::~TextureCache()
	{
		for (std::map<const char*, Texture*>::iterator itr = m_texture_map.begin(); itr != m_texture_map.end(); itr++) {
			delete itr->first;
			SDL_DestroyTexture(itr->second);
		}
		m_texture_map.clear();
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

		return m_texture_map[name];
	}

	void TextureCache::push(const char* name, RGB rgb) {
		Texture* ptr_texture = Graphics::instance()->load_texture(name, rgb);
		auto pair = std::make_pair(name, ptr_texture);
		m_texture_map.insert(pair);
	}
}