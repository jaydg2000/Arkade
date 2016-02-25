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
		Texture*									obtain(std::string& name);
		void										push(std::string& name, RGB rgb);

	private:
		static TextureCache*						m_ptr_instance;
		std::map<std::string, SDL_Texture*>			m_texture_map;

		TextureCache();
	};

}