#include "stdafx.h"
#include "PredatorSprite.h"


PredatorSprite::PredatorSprite(const char* filename, Size& frame_size)
	:SwimmingSprite(filename, frame_size)
{
	this->type(SPRITE_TYPE_PREDATOR);

	//go_to_start_position();
	
}


PredatorSprite::~PredatorSprite()
{
}



void PredatorSprite::go_to_start_position() {
	this->position_x(Random::rand_int(FishGame::res_width + 200, FishGame::res_width+400));
	this->position_y(Random::rand_int(450, 1200));
}

