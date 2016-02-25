#pragma once
#include <SDL.h>
#include <map>
#include <memory>
#include <string>
#include "Graphics.h"

using namespace std;

namespace arkade {

	class TextureCache {
	public:
		~TextureCache();

		static TextureCache*						instance();
		Texture*									obtain(const string& name);
		void										push(const string& name, RGB rgb);

	private:
		static TextureCache*						m_ptr_instance;
		map<const string&, SDL_Texture*>			m_texture_map;

		TextureCache();
	};

}