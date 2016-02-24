#pragma once
#include "Sprite.h"
#include "SpritePool.h"

namespace arkade {

	class CollisionDetector
	{
	public:
		CollisionDetector(void);
		~CollisionDetector(void);

		virtual void detect(Sprite* s1, Sprite* s2) = 0;
		virtual void detect(Sprite* sprite, SpritePool* sprite_pool) = 0;
		virtual void detect(SpritePool* sprite_pool1, SpritePool* sprite_pool2) = 0;
	};

}