#include "stdafx.h"
#include "MultipleBoundingBoxCollisionDetector.h"


MultipleBoundingBoxCollisionDetector::MultipleBoundingBoxCollisionDetector()
{
}


MultipleBoundingBoxCollisionDetector::~MultipleBoundingBoxCollisionDetector()
{
}

bool MultipleBoundingBoxCollisionDetector::detect(Collidable* c1, Collidable* c2) {
	
	if (!c1->collision_enabled() || !c2->collision_enabled())
		return false;

	list<Rect*> rects = c1->collision_regions();
	for each(Rect* ptr_rect in rects) {
		if (c2->has_collided(ptr_rect))
			return true;		
	}

	return false;
}