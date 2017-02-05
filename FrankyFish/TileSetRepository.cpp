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
	ptr_tile_def->add_collision_region(0, 0, 128, 100);
	
	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-edge-2.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(2, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 0, 128, 104);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-edge-rectangle.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(3, ptr_texture, 256, 128);
	ptr_tile_def->add_collision_region(0, 0, 256, 120);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-left-inner-corner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(4, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 5, 123, 123);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-left-outer-corner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(5, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(15, 0, 112, 114);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-right-inner-corner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(6, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(3, 4, 124, 123);

	ptr_texture = ptr_graphics->load_texture("res/tiles/bottom-right-outer-corner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(7, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 0, 108, 111);

	ptr_texture = ptr_graphics->load_texture("res/tiles/filler-rectangle.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(8, ptr_texture, 256, 128);
	ptr_tile_def->add_collision_region(0, 0, 256, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/filler-square.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(9, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 0, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-edge-vertical-rectangle.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(10, ptr_texture, 128, 256);
	ptr_tile_def->add_collision_region(15, 0, 113, 256);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-slope-1.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(11, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(15, 89, 112, 38);
	ptr_tile_def->add_collision_region(106, 64, 21, 26);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-slope-2.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(12, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 62, 68, 65);
	ptr_tile_def->add_collision_region(76, 24, 51, 103);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-slope-inner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(13, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 0, 128, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/left-vertical.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(14, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(20, 0, 107, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/mountain_1.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(15, ptr_texture, 768, 384);
	ptr_tile_def->add_collision_region(65, 8, 91, 51);
	ptr_tile_def->add_collision_region(159, 36, 43, 153);
	ptr_tile_def->add_collision_region(96, 61, 60, 33);
	ptr_tile_def->add_collision_region(119, 99, 40, 31);
	ptr_tile_def->add_collision_region(204, 141, 178, 242);
	ptr_tile_def->add_collision_region(141, 247, 51, 135);
	ptr_tile_def->add_collision_region(8, 360, 122, 23);
	ptr_tile_def->add_collision_region(385, 256, 113, 127);
	ptr_tile_def->add_collision_region(205, 86, 88, 52);
	ptr_tile_def->add_collision_region(499, 351, 201, 30);
	ptr_tile_def->add_collision_region(385, 198, 76, 54);
	ptr_tile_def->add_collision_region(500, 296, 55, 52);

	ptr_texture = ptr_graphics->load_texture("res/tiles/mountain_2.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(16, ptr_texture, 561, 384);
	ptr_tile_def->add_collision_region(76, 321, 443, 64);
	ptr_tile_def->add_collision_region(207, 102, 93, 73);
	ptr_tile_def->add_collision_region(237, 27, 36, 72);
	ptr_tile_def->add_collision_region(103, 270, 46, 47);
	ptr_tile_def->add_collision_region(163, 248, 179, 71);
	ptr_tile_def->add_collision_region(189, 178, 130, 65);
	ptr_tile_def->add_collision_region(10, 356, 64, 27);
	ptr_tile_def->add_collision_region(346, 281, 68, 38);
	ptr_tile_def->add_collision_region(428, 270, 41, 31);

	ptr_texture = ptr_graphics->load_texture("res/tiles/mountain_3.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(17, ptr_texture, 480, 512);
	ptr_tile_def->add_collision_region(148, 38, 93, 192);
	ptr_tile_def->add_collision_region(89, 237, 226, 271);

	ptr_texture = ptr_graphics->load_texture("res/tiles/mountain_4.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(18, ptr_texture, 384, 128);
	ptr_tile_def->add_collision_region(91, 60, 197, 65);
	ptr_tile_def->add_collision_region(15, 101, 72, 22);
	ptr_tile_def->add_collision_region(333, 101, 37, 25);
	ptr_tile_def->add_collision_region(137, 8, 54, 48);

	ptr_texture = ptr_graphics->load_texture("res/tiles/right-edge-vertical-rectangle.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(19, ptr_texture, 128, 256);
	ptr_tile_def->add_collision_region(0, 0, 115, 256);

	ptr_texture = ptr_graphics->load_texture("res/tiles/right-slope-2.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(20, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 61, 127, 66);
	ptr_tile_def->add_collision_region(1, 23, 53, 37);

	ptr_texture = ptr_graphics->load_texture("res/tiles/right-vertical.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(21, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 0, 110, 128);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-edge.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(23, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 29, 128, 98);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-edge-2.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(24, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 23, 128, 104);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-edge-rectangle.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(25, ptr_texture, 256, 128);
	ptr_tile_def->add_collision_region(0, 7, 256, 120);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-left-inner-corner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(26, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 0, 124, 124);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-left-outer-corner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(27, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(70, 19, 58, 108);
	ptr_tile_def->add_collision_region(24, 34, 45, 93);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-right-inner-corner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(28, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(4, 1, 123, 122);

	ptr_texture = ptr_graphics->load_texture("res/tiles/top-right-outer-corner.png", white);
	ptr_tile_def = ptr_tile_set->add_tile(29, ptr_texture, 128, 128);
	ptr_tile_def->add_collision_region(0, 22, 54, 105);
	ptr_tile_def->add_collision_region(56, 44, 45, 83);

	return ptr_tile_set;
}