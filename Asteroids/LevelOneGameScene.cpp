#include "LevelOneGameScene.h"

LevelOneGameScene::LevelOneGameScene()
{
}

LevelOneGameScene::~LevelOneGameScene()
{
}

void LevelOneGameScene::on_setup()
{
	m_ptr_background_image = new Image("res/images/space-background.png", make_size(1920,1200));
}

void LevelOneGameScene::on_begin()
{
}

void LevelOneGameScene::on_check_keyboard_input(Keyboard* ptr_keyboard)
{
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_ESCAPE)) {
		stop();
	}
}

void LevelOneGameScene::on_mouse_input()
{
}

void LevelOneGameScene::on_update()
{
}

void LevelOneGameScene::on_render(Graphics* ptr_graphics)
{
	ptr_graphics->render(m_ptr_background_image);
}

void LevelOneGameScene::on_end()
{
}

void LevelOneGameScene::on_cleanup()
{
}

void LevelOneGameScene::on_detect_collisions()
{
}
