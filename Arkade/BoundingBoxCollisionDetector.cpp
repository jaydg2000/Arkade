#include "BoundingBoxCollisionDetector.h"
#include "SpritePool.h"

namespace arkade {

	BoundingBoxCollisionDetector::BoundingBoxCollisionDetector(void)
	{
	}


	BoundingBoxCollisionDetector::~BoundingBoxCollisionDetector(void)
	{
	}

	void BoundingBoxCollisionDetector::detect(Sprite* s1, Sprite* s2) {
		if (!s1->is_visible() || !s2->is_visible())
			return;

		Rect r1 = s1->collision_rect();
		Rect r2 = s2->collision_rect();
		if (SDL_HasIntersection(&r1, &r2) == SDL_TRUE) {
			s1->on_collision(s2);
			s2->on_collision(s1);
		}
	}

	void BoundingBoxCollisionDetector::detect(Sprite* sprite, SpritePool* sprite_pool) {

		list<Sprite*>* sprite_list = sprite_pool->get_sprite_list();
		for (Sprite* pool_sprite : *sprite_list) {
			detect(sprite, pool_sprite);
		}

		//BoundingBoxCollisionDetector* collision_detector = this;
		//sprite_pool->for_each([collision_detector, sprite](Sprite* pool_sprite) {
		//	collision_detector->detect(sprite, pool_sprite);
		//});
	}

	void BoundingBoxCollisionDetector::detect(SpritePool* sprite_pool1, SpritePool* sprite_pool2) {

		list<Sprite*>* sprite_list_1 = sprite_pool1->get_sprite_list();
		list<Sprite*>* sprite_list_2 = sprite_pool2->get_sprite_list();

		for (Sprite* sprite1 : *sprite_list_1) {
			for (Sprite* sprite2 : *sprite_list_2) {
				detect(sprite1, sprite2);
			}
		}

		//BoundingBoxCollisionDetector* collision_detector = this;
		//sprite_pool1->for_each([collision_detector, sprite_pool2](Sprite* pool1_sprite) {
		//	collision_detector->detect(pool1_sprite, sprite_pool2);
		//});

	}
}