#pragma once
#include <Sprite.h>

using namespace arkade;

#define MIN_MOMENTUM              -7.0f
#define MAX_MOMENTUM              12.0f
#define MOMENTUM_STEP_UP          5.5f
#define MOMENTUM_STEP_DN           0.75f
#define MOMENTUM_AIR_STEP_DN       .25f

#define MIN_Y_POSITION          400.0f
#define MIN_Y_JUMP_POSITION     450.0f
#define MAX_Y_POSITION          1190.0f

#define MAX_ROTATION_UP         -355.0f
#define MAX_ROTATION_DOWN          5.0f

#define END_JUMP_DEPTH          1190.0f

class FrankySprite : public Sprite
{
public:
	FrankySprite();
	~FrankySprite();

	void				swim();
	void				idle();
	void				jump();
	virtual void		on_update() override;

private:
	float				m_momentum;	
	bool				m_is_jumping;

	void				tilt_down();
	void				tilt_up();
	void				tilt_straight();
};

