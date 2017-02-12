#include "ButtonSprite.h"


ButtonSprite::ButtonSprite(const char* resource_name, const Size& size) 
	: Sprite(resource_name, size)
{
}


ButtonSprite::~ButtonSprite()
{
}

bool ButtonSprite::is_clicked(float x, float y) {
	return intersects_with(x, y);
}