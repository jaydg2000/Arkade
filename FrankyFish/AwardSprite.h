#pragma once
#include "SwimmingSprite.h"

class AwardSprite : SwimmingSprite
{
public:
	AwardSprite(const char* filename, Size& frame_size);
	~AwardSprite();

	uint32_t						points();
	void							points(uint32_t points);

private:
	uint32_t						m_points;
};

