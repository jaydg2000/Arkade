#pragma once
#include <SDL.h>
#include <iostream>
#include <memory>
#include "ArkadeTypes.h"
#include "RGB.h"
#include "Camera.h"
#include "Sprite.h"
#include "Image.h"

namespace arkade
{
	struct RGB;
	class Graphics {
	public:

		Graphics();
		~Graphics();

		static Graphics*						instance();
		uint8_t									init(Camera* camera, bool full_screen, uint32_t width, uint32_t height, uint32_t color_depth, const char* psz_caption);
		void									pen_color(RGB rgb);
		RGB										pen_color();
		SDL_Texture*							load_texture(const std::string& path, RGB back_color = RGB(128, 0, 128)) const;
		void									push_pen_color(RGB rgb);
		void									pop_pen_color();
		void									render(Sprite* ptr_sprite);
		void									render(Image* ptr_image);
		void									begin_render();
		void									end_render();
		void									background_color(RGB rgb);

	private:

		static Graphics*						m_instance;
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
		RGB										m_background_color;

		uint8_t									clip(Rect* srcRect, Rect* destRect, Rect* clipRect);

	};
}
