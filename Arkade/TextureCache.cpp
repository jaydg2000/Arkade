#include "TextureCache.h"

namespace arkade {

	TextureCache::TextureCache()
	{
	}


	TextureCache::~TextureCache()
	{
	}

	TextureCache& TextureCache::instance() {
		if (!m_ptr_instance)
			m_ptr_instance = std::make_unique<TextureCache>(new TextureCache());
		return *m_ptr_instance;
	}

	weak_ptr<SDL_Texture> TextureCache::obtain(const string& name) {
		if (m_texture_map.count(name)<1) {
			shared_ptr<SDL_Texture> ptr_texture(Graphics::instance().load_texture(name));
			auto pair = make_pair(name, ptr_texture);
			m_texture_map.insert(pair);
		}

		return weak_ptr<SDL_Texture>(m_texture_map.at(name));
	}
}