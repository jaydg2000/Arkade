#include "Tile.h"

Tile::Tile(uint16_t type_id, Texture* ptr_texture, Flip flip, uint16_t rotation)
{
	_x = 0;
	_y = 0;
	_type_id = type_id;
	_ptr_texture = ptr_texture;
	_flip = flip;
	_rotation = rotation;
}

Tile::~Tile()
{
}

void Tile::position(float x, float y)
{
	_x = x;
	_y = y;
}

float Tile::position_x()
{
	return _x;
}

float Tile::position_y()
{
	return _y;
}

uint16_t Tile::tile_type()
{
	return _type_id;
}

Texture* Tile::texture()
{
	return _ptr_texture;
}

void Tile::flip(Flip render_flip)
{
	_flip = render_flip;
}

Flip Tile::flip()
{
	return _flip;
}

void Tile::rotation(uint16_t rotation)
{
	_rotation = rotation;
}

uint16_t Tile::rotation()
{
	return _rotation;
}

bool Tile::have_collided(Rect* source_rect)
{
	// todo: What do we want to do here?
	return false;
}
