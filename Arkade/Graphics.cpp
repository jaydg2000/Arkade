#include "Graphics.h"
#include <SDL_image.h>

namespace arkade {

	Graphics::Graphics()
	{
	}

	Graphics::~Graphics()
	{
		SDL_DestroyWindow(m_ptr_window);
		SDL_DestroyRenderer(m_ptr_renderer);
		SDL_QUIT;
	}

	const Graphics& Graphics::instance() {
		if (!m_instance)
			m_instance = std::make_unique<Graphics>();
		return *m_instance;
	}

	uint8_t Graphics::init(Camera* camera, bool full_screen, uint32_t width, uint32_t height, uint32_t color_depth, const char* psz_caption) {

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

		shared_ptr<SDL_Texture> texture = std::make_shared<SDL_Texture>(SDL_CreateTextureFromSurface(m_ptr_renderer, surface));
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

	void Graphics::render(const Sprite& sprite) const {

		sprite->on_pre_render();

		Rect* src_rect = renderable->source_rect();
		Rect* dest_rect = renderable->destination_rect();
		Rect* clip_rect = renderable->clip_rect();
		float rotation = renderable->rotation();
		Scale* scale = renderable->scale();
		uint8_t flip = renderable->flip();
		Texture* texture = renderable->texture();
		Vector2* coordinates = renderable->coordinates();
		Vector2* frame_center = renderable->frame_center();
		Vector2* camera_coordinates = m_ptr_camera->coordinates();

		dest_rect->x = coordinates->x - camera_coordinates->x;
		dest_rect->y = coordinates->y - camera_coordinates->y;

		if (clip_rect)
			if (!clip(src_rect, dest_rect, clip_rect))
				return;

		bool scale_is_normal = Scale::is_normal(scale);
		float previous_scale_x, previous_scale_y;

		if (!scale_is_normal) {
			SDL_RenderGetScale(m_ptr_renderer, &previous_scale_x, &previous_scale_y);
			SDL_RenderSetScale(m_ptr_renderer, scale->x, scale->y);
		}

		SDL_RenderCopyEx(
			m_ptr_renderer,
			texture->texture(),
			src_rect,
			dest_rect,
			rotation,
			frame_center,
			SDL_FLIP_NONE
			);

		renderable->on_post_render();
	}

	int Graphics::clip(SDL_Rect* srcRect, SDL_Rect* destRect, SDL_Rect* clipRect) {
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