#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <memory>
#include "ArkadeTypes.h"
#include "RGB.h"
#include "Camera.h"
#include "Sprite.h"
#include "SpritePool.h"
#include "Image.h"
#include "Font.h"
#include "Text.h"

namespace arkade
{
	struct RGB;
	class Graphics {
	public:

		Graphics();
		~Graphics();

		static Graphics*						instance();
		uint8_t									initialize(bool full_screen, uint32_t width, uint32_t height, uint32_t color_depth, const char* psz_caption);
		uint8_t									initialize(bool full_screen, uint32_t width, uint32_t height, uint32_t color_depth, uint32_t logical_width, uint32_t logical_height, const char* psz_caption);
		void									uninitialize();
		void									pen_color(RGB rgb);
		RGB										pen_color();
		SDL_Texture*							create_texture_from_surface(SDL_Surface* surface);
		SDL_Texture*							load_texture(const std::string& path, RGB back_color = RGB(0xFF, 0x00, 0xFF)) const;
		void									push_pen_color(RGB rgb);
		void									pop_pen_color();
		void									render(Texture* ptr_texture, float coordinate_x, float coordinate_y, Rect* src_rect, Flip flip, uint32_t rotation);
		void									render(Sprite* ptr_sprite);
		void									render(SpritePool* ptr_sprite_pool);
		void									render(const char* psz_text, uint32_t screen_x, uint32_t screen_y, Font* ptr_font, SDL_Color text_color = {255,255,255,255}, uint32_t rotation = 0);
		void									render(Text* text, uint32_t screen_x, uint32_t screen_y, uint32_t rotation = 0, Flip flip = FLIP_NONE);
		void									render(Image* ptr_image);
		void									render(Image* ptr_image, Size size);
		void									render(uint32_t nbr, Image* digit_source, uint8_t digit_width, uint8_t desired_places, float x, float y, uint8_t padding = 10);
		void									render(Rect* rect, RGB color = RGB::White, bool fill = false);
		void									render_bounding_box(Rect* ptr_rect);
		void									begin_render();
		void									end_render();
		void									background_color(RGB rgb);
		void									visible_bounding_box(bool is_visible);
		void									animation_on(bool should_animate);

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
		bool									m_show_bounding_box;
		bool									m_is_animating;
		RGB										m_bounding_box_color;
		RGB										m_stored_pen_color;
		RGB										m_background_color;
		Rect									m_destination_rect;
		uint8_t									clip(Rect* srcRect, Rect* destRect, Rect* clipRect);
		void									render_boundingBox(Rect* ptr_rect);

	};
}
