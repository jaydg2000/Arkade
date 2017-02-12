#pragma once
#include <Sprite.h>
#include "SpriteTypes.h"
#include "Collidable.h"

using namespace arkade;

class GameSprite : public Sprite	
{
public:
	GameSprite(const char* file_name, const Size& frame_size);
	~GameSprite();

	Rect*						collision_rect() override;
	void						enable_sound(bool enabled);
	bool						is_sound_enabled();
	virtual void				on_set_stage();
	void						start_position(float x, float y);

protected:
	bool						m_is_sound_enabled;
	void						collision_dim(uint32_t x_offset, uint32_t y_offset, uint32_t width, uint32_t height);
	
private:	
	Rect						m_collision_rect;
	uint32_t					m_collision_x_offset;
	uint32_t					m_collision_y_offset;
	uint32_t					m_collision_width;
	uint32_t					m_collision_height;
	float						m_start_x;
	float						m_start_y;
};

