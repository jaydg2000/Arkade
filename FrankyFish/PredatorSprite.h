#pragma once

#include "SwimmingSprite.h"

#include <Random.h>
#include "FishGame.h"

using namespace arkade;

class PredatorSprite : public SwimmingSprite
{
public:
	PredatorSprite(const char* filename, Size& frame_size);
	~PredatorSprite();


	void							go_to_start_position();


private:

	

};

