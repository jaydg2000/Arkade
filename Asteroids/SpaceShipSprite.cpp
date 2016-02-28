#include "SpaceShipSprite.h"
#include <OscillatingAnimator.h>


SpaceShipSprite::SpaceShipSprite()
	: PhysicsBasedSprite("res/images/PlayerSheet.png", arkade::make_size(66, 52))
{
	animator(new OscillatingAnimator(3, 200));
}


SpaceShipSprite::~SpaceShipSprite()
{
}
