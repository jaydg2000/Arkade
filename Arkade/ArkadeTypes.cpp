#include "ArkadeTypes.h"

namespace arkade {
	Size make_size(uint32_t x, uint32_t y) {
		Size s; s.x = x; s.y = y;
		return s;
	}
}