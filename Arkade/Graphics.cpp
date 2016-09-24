#include "Graphics.h"
#include <SDL_image.h>

namespace arkade {

	Graphics* Graphics::m_instance = nullptr;

	Graphics::Graphics()
	{
		m_show_bounding_box = false;
		m_is_animating = true;
		m_bounding_box_color = RGB(255, 0, 255);
	}

	Graphics::~Graphics()
	{
		SDL_DestroyWindow(m_ptr_window);
		SDL_DestroyRenderer(m_ptr_renderer);
		SDL_QUIT;
	}

	Graphics* Graphics::instance() {
		if (!m_instance)
			m_instance = new Graphics();
		return m_instance;
	}

	uint8_t Graphics::initialize(bool full_screen, uint32_t width, uint32_t height, uint32_t color_depth, const char* psz_caption) {
		m_ptr_camera = Camera::instance();
		m_full_screen = full_screen;
		m_window_width = width;
		m_window_height = height;
		m_color_depth = color_depth;
		m_psz_caption = psz_caption;

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			std::cout << "Could not init." << SDL_GetError();
			return 1;
		}

		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			std::cout << "Unable to Init hinting: " << SDL_GetError();
			SDL_Quit();
			return 2;
		}

		m_ptr_window = SDL_CreateWindow(
			m_psz_caption,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_window_width,
			m_window_height,
			m_full_screen ? SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN : SDL_WINDOW_SHOWN);

		if (!m_ptr_window) {
			std::cout << "Could not create window: " << SDL_GetError();
			SDL_Quit();
			return 3;
		}

		m_ptr_renderer = SDL_CreateRenderer(m_ptr_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!m_ptr_renderer) {
			SDL_Quit();
			std::cout << "Could not create renderer: " << SDL_GetError();
		}

		pen_color(RGB(0x00, 0x00, 0x00, 0xFF));

		return 0;
	}

	uint8_t Graphics::initialize(bool full_screen, uint32_t width, uint32_t height, uint32_t color_depth, uint32_t logical_width, uint32_t logical_height, const char* psz_caption) {
		uint8_t rcode = initialize(full_screen, width, height, color_depth, psz_caption);
		if (rcode != 0)
			return rcode;

		return SDL_RenderSetLogicalSize(m_ptr_renderer, logical_width, logical_height);
	}

	void Graphics::uninitialize() {
		SDL_DestroyWindow(m_ptr_window);
		SDL_DestroyRenderer(m_ptr_renderer);
		SDL_QUIT;
	}

	void Graphics::pen_color(RGB rgb) {
		SDL_SetRenderDrawColor(m_ptr_renderer, rgb.r, rgb.g, rgb.b, rgb.a);
	}

	RGB Graphics::pen_color() {
		RGB rgb;
		SDL_GetRenderDrawColor(m_ptr_renderer, &rgb.r, &rgb.g, &rgb.b, &rgb.a);
		return rgb;
	}

	SDL_Texture* Graphics::load_texture(const string& path, RGB back_color) const {
		SDL_Surface* surface = IMG_Load(path.c_str());
		if (!surface) {
			std::cout << "Could not load surface: " << SDL_GetError();
			SDL_Quit();
			return nullptr;
		}

		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, back_color.r, back_color.g, back_color.b));

		SDL_Texture* texture = SDL_CreateTextureFromSurface(m_ptr_renderer, surface);
		SDL_FreeSurface(surface);

		return texture;
	}

	void Graphics::push_pen_color(RGB rgb) {
		m_stored_pen_color = pen_color();
		pen_color(rgb);
	}

	void Graphics::pop_pen_color() {
		pen_color(m_stored_pen_color);
	}

	void Graphics::begin_render() {
		SDL_RenderClear(m_ptr_renderer);
	}

	void Graphics::end_render() {
		SDL_RenderPresent(m_ptr_renderer);
	}

	void Graphics::background_color(RGB rgb) {
		SDL_SetRenderDrawColor(m_ptr_renderer, rgb.r, rgb.g, rgb.b, rgb.a);
	}

	void Graphics::animation_on(bool should_animate) {
		m_is_animating = should_animate;
	}

	void Graphics::render(Sprite* sprite) {
		if (!sprite->is_visible())
			return;

		Rect* src_rect = sprite->source_rect();
		Rect* dest_rect = sprite->destination_rect();
		Rect* clip_rect = sprite->clip_rect();
		float rotation = sprite->rotation();
		uint8_t flip = sprite->flip();
		Texture* texture = sprite->texture();
		float coordinate_x = sprite->position_x();
		float coordinate_y = sprite->position_y();

		if (!sprite->use_screen_positioning()) {
			m_ptr_camera->to_screen(dest_rect, coordinate_x, coordinate_y);
		}

		if (clip_rect)
			if (!clip(src_rect, dest_rect, clip_rect))
				return;

		sprite->on_pre_render();

		SDL_RenderCopyEx(
			m_ptr_renderer,
			texture,
			src_rect,
			dest_rect,
			rotation,
			NULL,
			SDL_FLIP_NONE
			);

		if (m_show_bounding_box) {
			Rect* bounding_rect = sprite->collision_rect();
			if (!sprite->use_screen_positioning()) {
				m_ptr_camera->to_screen(bounding_rect, bounding_rect->x, bounding_rect->y);
			}
			render_boundingBox(bounding_rect);
		}

		sprite->on_post_render();
		if(m_is_animating)
			sprite->animate();
	}

	void Graphics::render(SpritePool* ptr_sprite_pool) {
		list<Sprite*>* sprite_list = ptr_sprite_pool->get_sprite_list();

		for (Sprite* sprite : *sprite_list) {
			render(sprite);
		}
	}

	void Graphics::render(Image* image) {
		Rect* destination_rect = image->destination_rect();

		if (!image->use_screen_positioning()) {
			m_ptr_camera->to_screen(destination_rect, image->x(), image->y());
		}

		SDL_RenderCopyEx(
			m_ptr_renderer,
			image->texture(),
			image->source_rect(),
			destination_rect,
			image->rotation(),
			NULL,
			image->flip()
			);
	}

	void Graphics::render(Image* image, Size size) {
		Rect* destination_rect = image->destination_rect();
		destination_rect->w = size.x;
		destination_rect->h = size.y;

		if (!image->use_screen_positioning()) {
			m_ptr_camera->to_screen(destination_rect, image->x(), image->y());
		}

		SDL_RenderCopyEx(
			m_ptr_renderer,
			image->texture(),
			image->source_rect(),
			destination_rect,
			image->rotation(),
			NULL,
			image->flip()
			);
	}

	void Graphics::render(const char* psz_text, uint32_t screen_x, uint32_t screen_y, Font* ptr_font) {
		Texture* ptr_texture = ptr_font->texture();
		Rect destination_rect;
		destination_rect.x = screen_x;
		destination_rect.y = screen_y;
		destination_rect.w = ptr_font->cell_size()->x;
		destination_rect.h = ptr_font->cell_size()->y;
		uint16_t pos = 0;
		do {
			Rect* source_rect = ptr_font->source_rect_for_character(psz_text[0]);
			destination_rect.x = (destination_rect.w * pos);
			pos++;

			SDL_RenderCopyEx(
				m_ptr_renderer,
				ptr_texture,
				source_rect,
				&destination_rect,
				0,
				NULL,
				SDL_FLIP_NONE
				);

		} while (psz_text);
	}

	void Graphics::render(uint32_t nbr, Image* digit_source, uint8_t digit_width, uint8_t desired_places, float x, float y, uint8_t padding) {
		char* nbr_str;
		nbr_str = new char[desired_places];
		Rect source_rect;
		Rect destination_rect;
		Texture* ptr_texture = digit_source->texture();

		source_rect.y = 0;
		source_rect.w = digit_width;
		source_rect.h = digit_source->source_rect()->h;

		destination_rect.y = y;
		destination_rect.w = digit_width;
		destination_rect.h = digit_source->source_rect()->h;

		SDL_uitoa(nbr, nbr_str, 10);
		for (int p = 0; p < desired_places; p++) {
			char c = nbr_str[p];
			int pos = c - 48;
			float screen_x = x + (p * digit_width);
			source_rect.x = pos * digit_width;
			destination_rect.x = screen_x;
			
			SDL_RenderCopyEx(
				m_ptr_renderer,
				ptr_texture,
				&source_rect,
				&destination_rect,
				0,
				NULL,
				SDL_FLIP_NONE
			);
		}

		delete nbr_str;
	}

	void Graphics::render_boundingBox(Rect* ptr_rect) {
		push_pen_color(m_bounding_box_color);
		SDL_RenderDrawRect(
			m_ptr_renderer,
			ptr_rect);
		pop_pen_color();
	}

	void Graphics::visible_bounding_box(bool is_visible) {
		m_show_bounding_box = is_visible;
	}

	uint8_t Graphics::clip(Rect* srcRect, Rect* destRect, Rect* clipRect) {
		// at this point, destRect has been converted to screen coordinates.

		int x = srcRect->x;
		int y = srcRect->y;
		int width = srcRect->w;
		int height = srcRect->h;

		int drawX = destRect->x;
		int drawY = destRect->y;
		int drawRight = drawX + (destRect->w - 1);
		int drawBottom = drawY + (destRect->h - 1);

		int clipLeft = clipRect->x;
		int clipRight = clipRect->x + (clipRect->w - 1);
		int clipTop = clipRect->y;
		int clipBottom = clipRect->y + (clipRect->h - 1);

		// No part of image is within clipping region.
		if (drawX > clipRight ||
			drawRight < clipLeft ||
			drawY > clipBottom ||
			drawBottom < clipTop)
			return 0;

		// Left side is off clipping region.
		if (drawX < clipLeft) {
			x = srcRect->x + (clipLeft - drawX);
			width = srcRect->w - (clipLeft - drawX);
			destRect->x = clipLeft;
		}

		// Right side is off clipping region.
		if (drawRight > clipRight) {
			width = srcRect->x - (drawRight - clipRight);
		}

		// Top is off clipping region.
		if (drawY < clipTop) {
			y = srcRect->y + (clipTop - drawY);
			height = srcRect->h - (clipTop - drawY);
			destRect->y = clipTop;
		}

		// Bottom is off clipping region.
		if (drawBottom > clipBottom)
		{
			height = srcRect->h - (drawBottom - clipBottom);
		}

		srcRect->x = x;
		srcRect->y = y;
		srcRect->w = width;
		srcRect->h = height;

		return 1;
	}

}