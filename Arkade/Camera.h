#pragma once
#include "ArkadeTypes.h"

namespace arkade {

	class Camera {
	public:
		Camera();
		~Camera();

		float				position_x();
		void				position_x(float x);
		float				position_y();
		void				position_y(float y);
		void				position(float x, float y);
		void				move_relative_x(float x);
		void				move_relative_y(float y);
		void				move_relative(float x, float y);
		int					x_to_screen(float x);
		int					y_to_screen(float y);
		void				to_screen(Rect* rect, float x, float y);

	private:
		float				m_x;
		float				m_y;
	};

}