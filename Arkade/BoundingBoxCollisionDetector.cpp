#include "BoundingBoxCollisionDetector.h"

namespace arkade {

	BoundingBoxCollisionDetector::BoundingBoxCollisionDetector(void)
	{
	}


	BoundingBoxCollisionDetector::~BoundingBoxCollisionDetector(void)
	{
	}

	void BoundingBoxCollisionDetector::detect(Sprite* s1, Sprite* s2) {
		Rect* r1 = s1->destination_rect();
		Rect* r2 = s2->destination_rect();
		if (SDL_HasIntersection(r1, r2) == SDL_TRUE) {
			s1->on_collision(s2);
			s2->on_collision(s1);
		}
	}

	void BoundingBoxCollisionDetector::detect(Sprite* sprite, SpritePool* sprite_pool) {
		BoundingBoxCollisionDetector* collision_detector = this;
		sprite_pool->for_each([collision_detector, sprite](Sprite* pool_sprite) {
			collision_detector->detect(sprite, pool_sprite);
		});
	}

	void BoundingBoxCollisionDetector::detect(SpritePool* sprite_pool1, SpritePool* sprite_pool2) {
		BoundingBoxCollisionDetector* collision_detector = this;
		sprite_pool1->for_each([collision_detector, sprite_pool2](Sprite* pool1_sprite) {
			collision_detector->detect(pool1_sprite, sprite_pool2);
		});

	}
}