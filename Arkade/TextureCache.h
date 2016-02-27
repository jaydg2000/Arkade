#pragma once
#include <SDL.h>
#include <map>
#include <memory>
#include <string>
#include "Graphics.h"

namespace arkade {

	class TextureCache {
	public:
		~TextureCache();

		static TextureCache*						instance();
		Texture*									obtain(const char* name);
		void										push(const char* name, RGB rgb);

	private:
		static TextureCache*						m_ptr_instance;
		std::map<const char*, SDL_Texture*>			m_texture_map;

		TextureCache();
	};

}