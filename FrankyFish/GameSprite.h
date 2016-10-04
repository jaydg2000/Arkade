#pragma once
#include <Sprite.h>
#include "SpriteTypes.h"
#include "Collidable.h"

using namespace arkade;

class GameSprite : public Sprite	
{
public:
	GameSprite(const char* file_name, Size& frame_size);
	~GameSprite();

	Rect*						collision_rect() override;

protected:
	void						collision_dim(uint32_t x_offset, uint32_t y_offset, uint32_t width, uint32_t height);

private:	
	Rect						m_collision_rect;
	uint32_t					m_collision_x_offset;
	uint32_t					m_collision_y_offset;
	uint32_t					m_collision_width;
	uint32_t					m_collision_height;
};

