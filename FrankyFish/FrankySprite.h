#pragma once
#include "GameSprite.h"
#include "SpriteTypes.h"
#include "MessageTypes.h"

using namespace arkade;

#define MIN_MOMENTUM            -12.0f
#define MAX_MOMENTUM              8.0f
#define MOMENTUM_STEP_DN         0.15f
#define MOMENTUM_AIR_STEP_DN      .35f

#define MIN_Y_POSITION          100.0f
#define MIN_Y_JUMP_POSITION     390.0f
#define MAX_Y_POSITION          1370.0f

#define MAX_ROTATION_UP         -355.0f
#define MAX_ROTATION_DOWN          5.0f

#define END_JUMP_DEPTH          450.0

class FrankySprite : public GameSprite
{
public:
	FrankySprite();
	~FrankySprite();

	void				boost();
	void				rest();
	void				jump();
	bool				can_restart();
	virtual void		on_update() override;
	virtual void		on_collision(Sprite* sprite) override;
	void				reset();

private:
	float				m_momentum;	
	float				m_rotation_increment;
	bool				m_is_jumping;
	bool				m_is_dead;

	void				tilt();
	//void				tilt_down();
	//void				tilt_up();
	//void				tilt_straight();
};

