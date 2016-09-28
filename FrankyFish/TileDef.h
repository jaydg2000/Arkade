#pragma once

#include <ArkadeTypes.h>
#include <queue>

using namespace std;
using namespace arkade;

class TileDef
{
public:
	TileDef();
	~TileDef();

	void					tile_type(uint32_t type_id);
	uint32_t				tile_type();
	void					texture(Texture* ptr_texture);
	Texture*				texture();
	Size*					size();
	void					size(uint32_t w, uint32_t h);

private:
	uint32_t				m_tile_type;
	Texture*				m_ptr_texture;
	Size					m_size;
};

