#include "LevelOneGameScene.h"
#include "Asteroids.h"
#include <Random.h>
#include <MathUtil.h>

LevelOneGameScene::LevelOneGameScene()
{
}

LevelOneGameScene::~LevelOneGameScene()
{
}

void LevelOneGameScene::on_setup()
{
	m_ptr_background = new Image("res/images/space-background.png", make_size(1920,1200));
	m_ptr_spaceship = new SpaceShipSprite();	
	register_sprite(m_ptr_spaceship);

	m_ptr_asteroid_pool = new SpritePool();
	
	for (uint8_t count = 0; count < 10; count++) {
		m_ptr_asteroid_pool->add(new AsteroidSprite("res/images/asteroid1.bmp", make_size(49,59)));
		m_ptr_asteroid_pool->add(new AsteroidSprite("res/images/asteroid2.bmp", make_size(29,33)));
		m_ptr_asteroid_pool->add(new AsteroidSprite("res/images/asteroid3.bmp", make_size(35,39)));
	}
	
}

void LevelOneGameScene::on_begin()
{
	m_ptr_spaceship->position(RES_WIDTH / 2, RES_HEIGHT / 2);
	m_asteroid_creation_timer.start(3000);
}

void LevelOneGameScene::on_check_keyboard_input(Keyboard* ptr_keyboard)
{
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_ESCAPE)) {
		stop();
	}
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_LEFT))
		m_ptr_spaceship->rotate_left(5);
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_RIGHT))
		m_ptr_spaceship->rotate_right(5);
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_UP))
		m_ptr_spaceship->accelerate();
	else {
		m_ptr_spaceship->friction();		
	}
}

void LevelOneGameScene::on_mouse_input()
{
}

void LevelOneGameScene::on_update()
{
	if (m_asteroid_creation_timer.has_elapsed())
		add_asteroid();
}

void LevelOneGameScene::on_render(Graphics* ptr_graphics)
{
	ptr_graphics->render(m_ptr_background);
	ptr_graphics->render(m_ptr_spaceship);
	ptr_graphics->render(m_ptr_asteroid_pool);
}

void LevelOneGameScene::on_end()
{
}

void LevelOneGameScene::on_cleanup()
{
	delete m_ptr_background;
	delete m_ptr_spaceship;
}

void LevelOneGameScene::on_detect_collisions()
{
}

void LevelOneGameScene::add_asteroid() {
	AsteroidSprite* asteroid = nullptr;
	asteroid = (AsteroidSprite*)m_ptr_asteroid_pool->obtain();
	if (!asteroid)
		return;

	float x, y;
	int8_t starting_side = Random::rand_int(0, 3);
	float heading = 0.0f;

	switch (starting_side) {
	case 2:
		x = Random::rand_int(0, RES_WIDTH);
		y = - 80;
		heading = Random::rand_int(115, 225);
		break;
	case 1:
		x = Random::rand_int(0, RES_WIDTH);
		y = RES_HEIGHT + 80;
		heading = Random::rand_int(280, 395);
		break;
	case 0:
		x = - 80;
		y = Random::rand_int(0, RES_HEIGHT);;
		heading = Random::rand_int(30, 165);
		break;
	case 3:
		x = RES_WIDTH + 80;
		y = Random::rand_int(0, RES_HEIGHT);;
		heading = Random::rand_int(195, 345);
		break;
	}

	asteroid->position(x, y);
	asteroid->heading(heading);
	register_sprite(asteroid);
}
