#include "ArkadeTypes.h"

namespace arkade {
	Size make_size(uint32_t x, uint32_t y) {
		Size s; s.x = x; s.y = y;
		return s;
	}

	Rect make_rect(int32_t x, int32_t y, int32_t w, int32_t h) {
		Rect r; r.x = x; r.y = y; r.w = w; r.h = h;
		return r;
	}

	Vector2 make_vector2(int32_t x, int32_t y) {
		Vector2 v; v.x = x; v.y = y;
		return v;
	}
}