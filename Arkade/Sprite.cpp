#include "Sprite.h"
#include "TextureCache.h"
#include "MathUtil.h"

namespace arkade {

	Sprite::Sprite()
	{
		m_bounds_lower_x =
			m_bounds_lower_y =
			m_bounds_upper_x =
			m_bounds_upper_y = -1;

		m_rotation = 0;

		m_enable_bounds_checking = false;
		m_flip = FLIP_NONE;
		m_ptr_animator = nullptr;
		m_ptr_texture = nullptr;

		m_source_rect.x = 0;
		m_source_rect.y = 0;
		m_source_rect.w = 0;
		m_source_rect.h = 0;

		m_ptr_clip_rect = nullptr;

		m_x = 0;
		m_y = 0;
	}

	Sprite::Sprite(const char* filename, Size& frame_size) : Sprite() {		
		texture(filename);
		m_frame_size.x = frame_size.x;
		m_frame_size.y = frame_size.y;

		m_source_rect.w = frame_size.x;
		m_source_rect.h = frame_size.y;
	}

	Sprite::~Sprite()
	{
	}

	void Sprite::animate() {
		if (m_ptr_animator)
			m_ptr_animator->animate();
	}

	void Sprite::animator(Animator* ptr_animator) {
		m_ptr_animator = ptr_animator;
	}

	Animator* Sprite::animator() {
		return m_ptr_animator;
	}

	void Sprite::texture(const char* filename, RGB back_color) {
		TextureCache* cache = TextureCache::instance();
		cache->push(filename, back_color);
		m_ptr_texture = cache->obtain(filename);		
	}

	Texture* Sprite::texture() {
		return m_ptr_texture;
	}

	float Sprite::position_x() {
		return m_x;
	}

	void Sprite::position_x(float x) {
		m_x = x;
		check_bounds();
	}

	float Sprite::position_y() {
		return m_y;
	}

	void Sprite::position_y(float y) {
		m_y = y;
		check_bounds();
	}

	void Sprite::position(float x, float y) {
		m_x = x;
		m_y = y;
		check_bounds();
	}

	void Sprite::move_relative_x(float relative_x) {
		m_x += relative_x;
		check_bounds();
	}

	void Sprite::move_relative_y(float relative_y) {
		m_y += relative_y;
		check_bounds();
	}

	void Sprite::move_at_heading(float heading, float distance) {
		double positionX = m_x;
		double positionY = m_y;
		double orientationInRadians = MathUtil::degrees_to_radians(heading);
		double xVector = sin(orientationInRadians);
		double yVector = cos(orientationInRadians);
		double magnitude = sqrt(xVector * xVector + yVector * yVector);
		double unitVectorX = xVector / magnitude;
		double unitVectorY = yVector / magnitude;
		m_x = (float)(positionX + unitVectorX * (distance));
		m_y = (float)(positionY + unitVectorY * (distance * -1));
	}

	float Sprite::rotation() {
		return m_rotation;
	}

	void Sprite::rotation(float rotation) {
		m_rotation = rotation;
	}

	void Sprite::rotate_left(float degrees) {
		m_rotation -= degrees;
		if (m_rotation < 0)
			m_rotation += 365;
	}

	void Sprite::rotate_right(float degrees) {
		m_rotation += degrees;
		if (m_rotation > 365)
			m_rotation -= 365;
	}

	bool Sprite::is_visible() {
		return m_is_visible;
	}

	void Sprite::is_visible(bool visible) {
		m_is_visible = visible;
	}

	void Sprite::bounds(float lower_x,
		float upper_x,
		float lower_y,
		float upper_y) {

		m_enable_bounds_checking = true;

		m_bounds_lower_x = lower_x;
		m_bounds_lower_y = lower_y;
		m_bounds_upper_x = upper_x;
		m_bounds_upper_y = upper_y;
	}

	void Sprite::check_bounds() {
		if (!m_enable_bounds_checking)
			return;

		if (m_x < m_bounds_lower_x)
			m_x = m_bounds_lower_x;
		if (m_x > m_bounds_upper_x)
			m_x = m_bounds_upper_x;
		if (m_y < m_bounds_lower_y)
			m_y = m_bounds_lower_y;
		if (m_y > m_bounds_upper_y)
			m_y = m_bounds_upper_y;
	}

	Size* Sprite::size() {
		return &m_frame_size;
	}

	uint32_t Sprite::size_x() {
		return m_frame_size.x;
	}

	uint32_t Sprite::size_y() {
		return m_frame_size.y;
	}

	void Sprite::size(Point& size_point) {
		m_frame_size.x = size_point.x;
		m_frame_size.y = size_point.y;
		m_frame_center.x = m_frame_size.x / 2;
		m_frame_center.y = m_frame_size.y / 2;
	}

	uint32_t Sprite::z_order() {
		return m_z_order;
	}

	void Sprite::z_order(uint32_t z_order) {
		m_z_order = z_order;
	}

	Flip Sprite::flip() {
		return m_flip;
	}

	void Sprite::flip(Flip flip) {
		m_flip = flip;
	}

	uint32_t Sprite::type() {
		return SPRITE_TYPE_UNKNOWN;
	}

	Rect* Sprite::source_rect() {
		uint32_t cframe;
		Animator* ptr_animator = m_ptr_animator;
		
		if (ptr_animator)
			cframe = m_ptr_animator->current_frame();
		else
			cframe = 0;

		m_source_rect.x = cframe * m_frame_size.x;
		return &m_source_rect;
	}

	Rect* Sprite::destination_rect() {
		m_destination_rect.x = (int)m_x;
		m_destination_rect.y = (int)m_y;
		m_destination_rect.w = m_frame_size.x;
		m_destination_rect.h = m_frame_size.y;
		return &m_destination_rect;
	}

	Rect* Sprite::clip_rect() {
		return m_ptr_clip_rect;
	}

	void Sprite::clip_rect(Rect& rect) {
		m_ptr_clip_rect->x = rect.x;
		m_ptr_clip_rect->y = rect.y;
		m_ptr_clip_rect->w = rect.w;
		m_ptr_clip_rect->h = rect.h;
	}

	Point* Sprite::center_frame() {
		return &m_frame_center;
	}

	void Sprite::on_setup() {
	}

	void Sprite::on_cleanup() {
	}

	void Sprite::on_update() {
	}

	void Sprite::on_pre_render() {
	}

	void Sprite::on_post_render() {
	}

	void Sprite::on_collision(Sprite* ptr_sprite_collided_with) {
	}

	void Sprite::on_pool_obtain() {
	}

	void Sprite::on_pool_release() {
	}
}