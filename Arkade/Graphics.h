#pragma once
#include <SDL.h>
#include <iostream>
#include <memory>
#include "ArkadeTypes.h"
#include "Camera.h"
#include "RGB.h"
#include "Sprite.h"

using namespace std;

namespace arkade
{
	class Graphics {
	public:

		Graphics();
		~Graphics();

		static Graphics*						instance();
		uint8_t									init(Camera* camera, bool full_screen, uint32_t width, uint32_t height, uint32_t color_depth, const char* psz_caption);
		void									pen_color(RGB rgb);
		RGB										pen_color();
		SDL_Texture*							load_texture(const string& path, RGB back_color = RGB(128, 0, 128)) const;
		void									push_pen_color(RGB rgb);
		void									pop_pen_color();
		void									render(Sprite* sprite) const;

	private:

		static unique_ptr<Graphics>				m_instance;
		SDL_Window*								m_ptr_window;
		SDL_Renderer*							m_ptr_renderer;
		Camera*									m_ptr_camera;
		const char*								m_psz_caption;
		uint32_t								m_window_width;
		uint32_t								m_window_height;
		uint32_t								m_color_depth;
		bool									m_full_screen;

		bool									m_showBoundingBox;
		bool									m_showTileBoundingBox;
		bool									m_showClippingRegion;
		RGB										m_boundingBoxColor;
		RGB										m_clipRegionColor;
		RGB										m_stored_pen_color;

		int										clip(Rect* srcRect, Rect* destRect, Rect* clipRect);

	};
}
