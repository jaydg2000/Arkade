#include "SpaceShipSprite.h"
#include "LaserSprite.h"
#include <OscillatingAnimator.h>
#include <TextureCache.h>
#include <ArkadeTypes.h>
#include "MathUtil.h"
#include "Asteroids.h"

SpaceShipSprite::SpaceShipSprite(uint32_t screen_width, uint32_t screen_height, BoundsChecker* bounds_checker, Sound* ptr_laser_sound)
	: PhysicsBasedSprite("res/images/PlayerSheet.png", arkade::make_size(66, 52))
{
	type(SPRITE_TYPE_PLAYER);
	m_engine_on_animator = new OscillatingAnimator(3, 150);
	animator(m_engine_on_animator);
	m_frame_size.x = 66;
	m_frame_size.y = 52;
	m_engine_on_texture = texture();
	m_screen_center_x = screen_width / 2;
	m_screen_center_y = screen_height / 2;

	m_bounds_checker = bounds_checker;

	m_laser_fire_timer.start(200);
	m_laser_sound = ptr_laser_sound;
}


SpaceShipSprite::~SpaceShipSprite()
{
}

void SpaceShipSprite::on_setup() {
	register_for_messages(MESSAGE_TYPE_LASER_DEAD);
	m_engine_off_texture = TextureCache::instance()->obtain("res/images/playersheet_nopower.png");
	init_laser_pool();
}

void SpaceShipSprite::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {
	if (message_type == MESSAGE_TYPE_LASER_DEAD) {
		LaserSprite* ptr_sprite = (LaserSprite*)ptr_data;
		m_ptr_laser_pool->release(ptr_sprite);
	}
}

void SpaceShipSprite::on_update() {
	
	PhysicsBasedSprite::on_update();

	if (!is_visible()) {
		if (m_death_timer.has_elapsed()) {
			m_death_timer.stop();
			is_visible(true);
			reset_position();
		}
	}

	apply_texture();
	check_bounds();
}

void SpaceShipSprite::on_collision(Sprite* ptr_colliding_sprite) {
	if (!is_visible())
		return;
	if (ptr_colliding_sprite->type() == SPRITE_TYPE_ASTEROID) {
		send_explosion_message();
		is_visible(false);
		m_death_timer.start(3000);
	}
}

void SpaceShipSprite::apply_texture() {
	if (m_thrust_on) {
		texture(m_engine_on_texture);
		animator(m_engine_on_animator);
	}
	else {
		texture(m_engine_off_texture);
		animator(nullptr);
	}
}

void SpaceShipSprite::check_bounds() {
	float x = position_x();
	float y = position_y();

	if (m_bounds_checker->is_out_of_bounds(x,y))
		reset_position();
}

void SpaceShipSprite::reset_position() {
	stop();
	position(m_screen_center_x, m_screen_center_y);
	rotation(0);
}

void SpaceShipSprite::thrust(bool is_on) {
	m_thrust_on = is_on;
}

LaserSprite* SpaceShipSprite::fire() {
	if (!is_visible() || !m_laser_fire_timer.has_elapsed())
		return nullptr;

	Sprite* ptr_sprite = m_ptr_laser_pool->obtain();
	if (!ptr_sprite)
		return nullptr;

	LaserSprite* ptr_laser_sprite = (LaserSprite*)ptr_sprite;

	ptr_laser_sprite->rotation(rotation());
	ptr_laser_sprite->position_x(position_x()+29);
	ptr_laser_sprite->position_y(position_y()+19);
	ptr_laser_sprite->move_at_heading(rotation(), 26);

	m_laser_sound->play_sound();

	return ptr_laser_sprite;
}

void SpaceShipSprite::init_laser_pool() {
	m_ptr_laser_pool = new SpritePool();
	for (uint8_t count = 0; count < 30; count++) {
		m_ptr_laser_pool->add(new LaserSprite(m_bounds_checker));
	}
}

SpritePool* SpaceShipSprite::laser_sprite_pool() {
	return m_ptr_laser_pool;
}

void SpaceShipSprite::send_explosion_message() {
	Message* message = obtain_message();

	PointF* position = new PointF();
	position->x = position_x();
	position->y = position_y();
	message->set(MESSAGE_TYPE_CREATE_EXPLOSION, nullptr, position);
	send_message(message);
}
