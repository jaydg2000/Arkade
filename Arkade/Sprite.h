#pragma once
#include <SDL.h>
#include "RGB.h"
#include "Point.h"
#include "PointF.h"
#include "Animator.h"
#include "MessageSink.h"
#include "MessageBroadcaster.h"
#include "ArkadeTypes.h"

#define SPRITE_TYPE_UNKNOWN 0

namespace arkade {

	class Sprite : public MessageSink, public MessageBroadcaster {
	public:
		Sprite();
		Sprite(const char* filename, Size& frame_size);
		~Sprite();

		void					texture(const char* filename, RGB back_color = RGB::Magenta);
		Texture*				texture();
		Texture*				texture(Texture* ptr_texture);
		void					animator(Animator* ptr_animator);
		Animator*				animator();
		void					animate();
		float					position_x();
		void					position_x(float x);
		void					move_relative_x(float relative_x);
		float					position_y();
		void					position_y(float y);
		void					position(float x, float y);
		void					move_relative_y(float relative_y);
		void					move_at_heading(float heading, float distance);
		float					rotation();
		void					rotation(float rotation);
		void					rotate_left(float degrees);
		void					rotate_right(float degrees);
		//void					scale(float x, float y);
		//void					scale(PointF& point);
		//PointF					scale();
		uint32_t				size_x();
		uint32_t				size_y();
		Size*					size();
		void					size(Point& size);
		uint32_t				z_order();
		void					z_order(uint32_t z_order);
		Flip					flip();
		void					flip(Flip flip);
		bool					is_visible();
		void					is_visible(bool visible);
		bool					use_screen_positioning();
		void					use_screen_positioning(bool enabled);
		void					bounds(
									float lower_x,
									float upper_x,
									float lower_y,
									float upper_y);
		
		virtual Rect*			source_rect();
		virtual Rect*			destination_rect();
		virtual Rect*			clip_rect();
		void					clip_rect(Rect& rect);
		virtual Point*			center_frame();
		void					type(uint32_t type);
		uint32_t				type();
		
		virtual void			on_setup();
		virtual void			on_cleanup();
		virtual void			on_update();
		virtual void			on_pre_render();
		virtual void			on_post_render();
		virtual void			on_collision(Sprite* ptr_sprite_collided_with);
		virtual void			on_pool_obtain();
		virtual void			on_pool_release();

	private:
		uint32_t				m_type;
		float					m_x;
		float					m_y;
		float					m_bounds_lower_x;
		float					m_bounds_lower_y;
		float					m_bounds_upper_x;
		float					m_bounds_upper_y;
		float					m_rotation;
		float					m_scale_x;
		float					m_scale_y;
		Size					m_frame_size;
		uint32_t				m_z_order;
		Flip					m_flip;
		bool					m_is_visible;
		bool					m_enable_bounds_checking;
		bool					m_use_screen_positioning;
		Texture*				m_ptr_texture;
		Animator*				m_ptr_animator;
		Rect					m_source_rect;
		Rect					m_destination_rect;
		Rect*					m_ptr_clip_rect;
		Point					m_frame_center;

		void					check_bounds();
	};
}