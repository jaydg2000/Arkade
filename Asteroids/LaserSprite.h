#pragma once
#include <Sprite.h>

using namespace arkade;

class LaserSprite : public Sprite {
public:
	LaserSprite();
	~LaserSprite();

protected:
	void				on_update();
};

