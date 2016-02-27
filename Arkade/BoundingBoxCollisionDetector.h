#pragma once
#include "CollisionDetector.h"


namespace arkade {
	class SpritePool;
	class BoundingBoxCollisionDetector : public CollisionDetector
	{
	public:
		BoundingBoxCollisionDetector(void);
		~BoundingBoxCollisionDetector(void);

		virtual void detect(Sprite* s1, Sprite* s2);
		virtual void detect(Sprite* sprite, SpritePool* sprite_pool);
		virtual void detect(SpritePool* sprite_pool1, SpritePool* sprite_pool2);

	};

}