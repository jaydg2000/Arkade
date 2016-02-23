#pragma once
#include <string>
#include "Point.h"
#include "PointF.h"
#include "TextureCache.h"
#include "SpriteBehavior.h"
#include "__arkade_spr_registry.h"

using namespace std;

namespace arkade {

	class Sprite {
	public:
		Sprite();
		~Sprite();

		const void				texture(const string& filename);
		float					position_x();
		void					position_x(float x);
		void					move_relative_x(float relative_x);
		float					position_y();
		void					position_y(float y);
		void					position(float x, float y);
		void					move_relative_y(float relative_y);
		void					scale(float x, float y);
		void					scale(PointF& point);
		PointF					scale();
		uint32_t				size_x();
		uint32_t				size_y();
		Point					size();
		void					size(Point& size);
		uint32_t				z_order();
		void					z_order(uint32_t z_order);
		bool					is_visible();
		void					is_visible(bool visible);
		void					behavior(SpriteBehavior* ptr_behavior);
		void					bounds(	int32_t lower_x, 
										int32_t upper_x, 
										int32_t lower_y, 
										int32_t upper_y);

	private:

		float					m_x;
		float					m_y;
		uint32_t				m_size_x;
		uint32_t				m_size_y;
		float					m_bounds_lower_x;
		float					m_bounds_lower_y;
		float					m_bounds_upper_x;
		float					m_bounds_upper_y;
		float					m_rotation;
		float					m_scale_x;
		float					m_scale_y;
		uint32_t				m_z_order;
		bool					m_is_visible;
		bool					m_enable_bounds_checking;
		weak_ptr<SDL_Texture>	m_ptr_texture;
		SpriteBehavior*			m_ptr_behavior;

		void					check_bounds();
	};
}