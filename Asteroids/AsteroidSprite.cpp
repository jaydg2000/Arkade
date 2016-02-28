#include "AsteroidSprite.h"
#include <Random.h>

AsteroidSprite::AsteroidSprite(const char* filename, Size texture_size)
	:Sprite(filename, texture_size)
{
	m_speed = Random::rand_int(1,4);
	m_rotation_rate = Random::rand_int(0, 15);
	m_heading = 0;
}


AsteroidSprite::~AsteroidSprite()
{
}

void AsteroidSprite::heading(float heading) {
	m_heading = heading;
}

void AsteroidSprite::on_update() {
	move_at_heading(m_heading, m_speed);
	rotation(rotation() + m_rotation_rate);
}