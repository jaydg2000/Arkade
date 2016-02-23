#pragma once

namespace arkade {

	struct Scale {

		Scale() {
			NORMAL.x = 1.0f; NORMAL.y = 1.0f;
		}

		Scale(float x, float y) {
			this->x = x; this->y = y;
			Scale();
		}
		
		static bool is_normal(Scale* scale) {
			return (scale->x == 1.0f && scale->y == 1.0f);
		}

		static Scale NORMAL;

		float x;
		float y;
	};
}