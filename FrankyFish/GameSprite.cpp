#include "GameSprite.h"


GameSprite::GameSprite(const char* file_name, const Size& frame_size)
	:Sprite(file_name, frame_size)
{
	m_collision_x_offset = 0;
	m_collision_y_offset = 0;
	m_collision_width = frame_size.x;
	m_collision_height = frame_size.y;
}


GameSprite::~GameSprite()
{
}

void GameSprite::collision_dim(uint32_t x_offset, uint32_t y_offset, uint32_t width, uint32_t height) {
	m_collision_x_offset = x_offset;
	m_collision_y_offset = y_offset;
	m_collision_width = width;
	m_collision_height = height;
}

Rect* GameSprite::collision_rect() {
	Rect* ptr_rect = destination_rect();
	m_collision_rect.x = ptr_rect->x + m_collision_x_offset;
	m_collision_rect.y = ptr_rect->y + m_collision_y_offset;
	m_collision_rect.w = m_collision_width;
	m_collision_rect.h = m_collision_height;

	return &m_collision_rect;
}

void GameSprite::enable_sound(bool enabled) {
	m_is_sound_enabled = enabled;
}

bool GameSprite::is_sound_enabled() {
	return m_is_sound_enabled;
}

void GameSprite::on_set_stage() {
	position(m_start_x, m_start_y);
}

void GameSprite::start_position(float x, float y) {
	m_start_x = x;
	m_start_y = y;
	position(x,y);
}