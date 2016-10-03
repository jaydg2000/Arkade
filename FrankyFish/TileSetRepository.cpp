#include "stdafx.h"
#include "TileSetRepository.h"


TileSetRepository::TileSetRepository() {
}


TileSetRepository::~TileSetRepository() {
}

TileSet* TileSetRepository::load_tile_set() {
	Graphics* ptr_graphics = Graphics::instance();
	TileSet* ptr_tile_set = new TileSet();
	RGB white = RGB(255, 255, 255);

	Texture* ptr_texture;
	TileDef* ptr_tile_def;

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-edge.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(1, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 0, 127, 86);
	ptr_tile_def->add_collision_region(0, 87, 45, 16);
	ptr_tile_def->add_collision_region(80, 87, 47, 17);
	
	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-edge-2.png", white);
	ptr_tile_set->add_tile(2, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-edge-rectangle.png", white);
	ptr_tile_set->add_tile(3, ptr_texture, 256, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-left-inner-corner.png", white);
	ptr_tile_set->add_tile(4, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-left-outer-corner.png", white);
	ptr_tile_set->add_tile(5, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-right-inner-corner.png", white);
	ptr_tile_set->add_tile(6, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-right-outer-corner.png", white);
	ptr_tile_set->add_tile(7, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/filler-rectangle.png", white);
	ptr_tile_set->add_tile(8, ptr_texture, 256, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/filler-square.png", white);
	ptr_tile_set->add_tile(9, ptr_texture, 128, 256);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-edge-vertical-rectangle.png", white);
	ptr_tile_set->add_tile(10, ptr_texture, 128, 256);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-slope-1.png", white);
	ptr_tile_set->add_tile(11, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-slope-2.png", white);
	ptr_tile_set->add_tile(12, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-slope-inner.png", white);
	ptr_tile_set->add_tile(13, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-vertical.png", white);
	ptr_tile_set->add_tile(14, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/mountain_1.png", white);
	ptr_tile_set->add_tile(15, ptr_texture, 768, 384);

	ptr_texture = ptr_graphics->load_texture("res/tiles/mountain_2.png", white);
	ptr_tile_set->add_tile(16, ptr_texture, 561, 384);

	ptr_texture = ptr_graphics->load_texture("res/tiles/mountain_3.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(17, ptr_texture, 480, 512);
	ptr_tile_def->add_collision_region(148, 38, 93, 192);
	ptr_tile_def->add_collision_region(89, 237, 226, 271);

	ptr_texture = ptr_graphics->load_texture("res/tiles/mountain_4.png", white);
	ptr_tile_set->add_tile(18, ptr_texture, 384, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/right-edge-vertical-rectangle.png", white);
	ptr_tile_set->add_tile(19, ptr_texture, 128, 256);

	ptr_texture = ptr_graphics->load_texture("res/tiles/right-slope-2.png", white);
	ptr_tile_set->add_tile(20, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/right-vertical.png", white);
	ptr_tile_set->add_tile(21, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-edge.png", white);
	ptr_tile_set->add_tile(23, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-edge-2.png", white);
	ptr_tile_set->add_tile(24, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-edge-rectangle.png", white);
	ptr_tile_set->add_tile(25, ptr_texture, 256, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-left-inner-corner.png", white);
	ptr_tile_set->add_tile(26, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-left-outer-corner.png", white);
	ptr_tile_set->add_tile(27, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-right-inner-corner.png", white);
	ptr_tile_set->add_tile(28, ptr_texture, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-right-outer-corner.png", white);
	ptr_tile_set->add_tile(29, ptr_texture, 128, 128);

	return ptr_tile_set;
}