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
	register_for_messages(MESSAGE_TYPE_ASTEROID_DEAD);
	register_for_messages(MESSAGE_TYPE_LASER_DEAD);
	register_for_messages(MESSAGE_TYPE_EXPLOSION_DEAD);
	register_for_messages(MESSAGE_TYPE_CREATE_EXPLOSION);

	m_bounds_checker = new BoundsChecker(-500, -500, RES_WIDTH + 500, RES_HEIGHT + 500);

	m_ptr_asteroid_explosion_sound = new Sound("res/wav/implosion2.wav");
	m_ptr_laser_sound = new Sound("res/wav/laserfire3.wav");
	//m_ptr_spaceship_explosion_sound = new Sound("res/wav/explosion2.wav");
	//m_ptr_scream_sound = new Sound("res/wav/scream1.wav");

	m_ptr_background = new Image("res/images/space-background.png", make_size(1920,1280));
	m_ptr_background->destination_rect(make_rect(0, 0, 1366, 768));
	m_ptr_spaceship = new SpaceShipSprite(RES_WIDTH, RES_HEIGHT, m_bounds_checker, m_ptr_laser_sound/*, m_ptr_scream_sound, m_ptr_spaceship_explosion_sound*/);	
	register_sprite(m_ptr_spaceship);

	init_asteroid_pool();
	init_explosion_pool();
}

void LevelOneGameScene::init_asteroid_pool() {
	m_ptr_asteroid_pool = new SpritePool();

	for (uint8_t count = 0; count < 15; count++) {
		m_ptr_asteroid_pool->add(new AsteroidSprite("res/images/asteroid1.bmp", make_size(49, 59), m_bounds_checker, m_ptr_asteroid_explosion_sound));
		m_ptr_asteroid_pool->add(new AsteroidSprite("res/images/asteroid2.bmp", make_size(29, 33), m_bounds_checker, m_ptr_asteroid_explosion_sound));
		m_ptr_asteroid_pool->add(new AsteroidSprite("res/images/asteroid3.bmp", make_size(35, 39), m_bounds_checker, m_ptr_asteroid_explosion_sound));
	}
}

void LevelOneGameScene::init_explosion_pool() {
	m_ptr_explosion_pool = new SpritePool();
	
	for (uint8_t count = 0; count < 10; count++) {
		m_ptr_explosion_pool->add(new ExplosionSprite());
	}
}

void LevelOneGameScene::on_begin()
{
	m_ptr_spaceship->position(RES_WIDTH / 2, RES_HEIGHT / 2);
	m_asteroid_creation_timer.start(750);
}

void LevelOneGameScene::on_check_keyboard_input(Keyboard* ptr_keyboard)
{
//ifdef _DEBUG
//	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_F1)) {
//		__debugbreak();
//	}
//endif

	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_ESCAPE)) {
		stop();
	}
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_SPACE)) {
		add_laser();
	}
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_LEFT))
		m_ptr_spaceship->rotate_left(5);
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_RIGHT))
		m_ptr_spaceship->rotate_right(5);
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_UP)) {
		m_ptr_spaceship->accelerate();
		m_ptr_spaceship->thrust(true);
	}
	else {
		m_ptr_spaceship->friction();		
		m_ptr_spaceship->thrust(false);
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
	ptr_graphics->render(m_ptr_background, make_size(RES_WIDTH, RES_HEIGHT));
	ptr_graphics->render(m_ptr_spaceship->laser_sprite_pool());
	ptr_graphics->render(m_ptr_spaceship);
	ptr_graphics->render(m_ptr_asteroid_pool);
	ptr_graphics->render(m_ptr_explosion_pool);
	//ptr_graphics->render("SCORE", 10, 10, m_ptr_font);
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
	m_collision_detector.detect(m_ptr_spaceship->laser_sprite_pool(), m_ptr_asteroid_pool);
	m_collision_detector.detect(m_ptr_spaceship, m_ptr_asteroid_pool);
}

void LevelOneGameScene::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {

	PointF* position = nullptr;
	AsteroidSprite* sprite = nullptr;
	ExplosionSprite* exp_sprite = nullptr;
	
	switch (message_type) {

		case MESSAGE_TYPE_CREATE_EXPLOSION:
			position = (PointF*)ptr_data;
			add_explosion(position);
			break;

		case MESSAGE_TYPE_LASER_DEAD:
			unregister_sprite((LaserSprite*)ptr_data);
			break;

		case MESSAGE_TYPE_ASTEROID_DEAD:
			sprite = (AsteroidSprite*)ptr_data;
			unregister_sprite(sprite);
			m_ptr_asteroid_pool->release(sprite);
			break;

		case MESSAGE_TYPE_EXPLOSION_DEAD:
			exp_sprite = (ExplosionSprite*)ptr_data;
			unregister_sprite(exp_sprite);
			m_ptr_explosion_pool->release(exp_sprite);
			break;
	}
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

void LevelOneGameScene::add_laser() {
	LaserSprite* sprite = m_ptr_spaceship->fire();
	if (!sprite)
		return;

	register_sprite(sprite);
}

void LevelOneGameScene::add_explosion(PointF* position) {
	ExplosionSprite* sprite = (ExplosionSprite*)m_ptr_explosion_pool->obtain();
	if (!sprite)
		return;

	register_sprite(sprite);

	sprite->position(position->x, position->y);
	sprite->animator()->start();
}
