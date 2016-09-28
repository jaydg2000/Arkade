#pragma once

#include "Collidable.h"

class MultipleBoundingBoxCollisionDetector
{
public:
	MultipleBoundingBoxCollisionDetector();
	~MultipleBoundingBoxCollisionDetector();

	bool						detect(Collidable* c1, Collidable* c2);
};

