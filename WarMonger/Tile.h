#pragma once
#include <ArkadeTypes.h>

using namespace arkade;

class Tile
{
public:
	Tile(
		uint16_t type_id, 
		Texture* ptr_texture, 
		Flip flip = FLIP_NONE, 
		uint16_t rotation = 0.0f);
	~Tile();

	void								position(float x, float y);
	float								position_x();
	float								position_y();
	uint16_t							tile_type();
	Texture*							texture();
	void								flip(Flip render_flip);
	Flip								flip();
	void								rotation(uint16_t rotation);
	uint16_t							rotation();
	bool								have_collided(Rect* source_rect);

private:
	uint16_t							_type_id;
	float								_x;
	float								_y;
	Flip								_flip;
	uint16_t							_rotation;
	Texture*							_ptr_texture;
};

