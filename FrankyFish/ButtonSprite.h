#pragma once
#include <Sprite.h>

using namespace arkade;

class ButtonSprite : public Sprite
{
public:
	ButtonSprite(const char* resource_name, const Size& size);
	~ButtonSprite();

	bool					is_clicked(float x, float y);
};

