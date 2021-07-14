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

	Rect copy_rect(Rect* source_rect)
	{
		Rect r;
		r.x = source_rect->x;
		r.y = source_rect->y;
		r.w = source_rect->w;
		r.h = source_rect->h;
		return r;
	}

	void expand_rect(Rect* rect_to_expand, Size margin)
	{
		rect_to_expand->w += (margin.x*2);
		rect_to_expand->x -= margin.x;
		rect_to_expand->h += (margin.y*2);
		rect_to_expand->y -= margin.y;
	}

	Vector2 make_vector2(int32_t x, int32_t y) {
		Vector2 v; v.x = x; v.y = y;
		return v;
	}
}