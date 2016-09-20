#pragma once
#include "ArkadeTypes.h"

namespace arkade {

	class Image {
	public:
		Image(const char* filename, Size texture_size, float x=0.0f, float y=0.0f);
		~Image();

		Texture*				texture();
		float					x();
		float					y();
		void					x(float x);
		void					y(float y);
		float					rotation();
		void					rotation(float rotation);		
		Flip					flip();
		void					flip(Flip flip);
		bool					use_screen_positioning();
		void					use_screen_positioning(bool enabled);

		virtual Rect*			source_rect();
		void					source_rect(Rect& rect);
		virtual Rect*			destination_rect();
		void					destination_rect(Rect& rect);

	private:
		float					m_x;
		float					m_y;
		float					m_rotation;
		bool					m_use_screen_positioning;
		Flip					m_flip;
		Size					m_size;
		Texture*				m_ptr_texture;
		Rect					m_source_rect;
		Rect					m_destination_rect;
	};

}