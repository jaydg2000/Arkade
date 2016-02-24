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
		weak_ptr<SDL_Texture>						obtain(const string& name);
		void										push(const string& name, RGB rgb);

	private:
		static unique_ptr<TextureCache>				m_ptr_instance;
		map<const string&, shared_ptr<SDL_Texture>>	m_texture_map;

		TextureCache();
	};

}