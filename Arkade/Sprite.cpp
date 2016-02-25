#include "Sprite.h"
#include "__arkade_spr_registry.h"
#include "TextureCache.h"

namespace arkade {

	Sprite::Sprite()
	{
		m_bounds_lower_x =
			m_bounds_lower_y =
			m_bounds_upper_x =
			m_bounds_upper_y = -1;

		m_enable_bounds_checking = false;

		__arkade_spr_registry* sprite_registry = __arkade_spr_registry::instance();
		sprite_registry->add(this);
	}

	Sprite::Sprite(string& filename) {
		Sprite();
		texture(filename);
	}

	Sprite::~Sprite()
	{
	}

	void Sprite::animator(Animator* ptr_animator) {
		m_ptr_animator = ptr_animator;
	}

	Animator* Sprite::animator() {
		return m_ptr_animator;
	}

	void Sprite::texture(string& filename, RGB back_color) {
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

	float Sprite::rotation() {
		return m_rotation;
	}

	void Sprite::rotation(float rotation) {
		m_rotation = rotation;
	}

	bool Sprite::is_visible() {
		return m_is_visible;
	}

	void Sprite::is_visible(bool visible) {
		m_is_visible = visible;
	}

	PointF Sprite::scale() {
		PointF pointF;
		pointF.x = m_scale_x;
		pointF.y = m_scale_y;
		return pointF;
	}

	void Sprite::scale(float x, float y) {
		m_scale_x = x;
		m_scale_y = y;
	}

	void Sprite::scale(PointF& scale) {
		m_scale_x = scale.x;
		m_scale_y = scale.y;
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

	Point Sprite::size() {
		Point size_point;
		size_point.x = m_size_x;
		size_point.y = m_size_y;
		return size_point;
	}

	uint32_t Sprite::size_x() {
		return m_size_x;
	}

	uint32_t Sprite::size_y() {
		return m_size_y;
	}

	void Sprite::size(Point& size_point) {
		m_size_x = size_point.x;
		m_size_y = size_point.y;
	}

	uint32_t Sprite::z_order() {
		return m_z_order;
	}

	void Sprite::z_order(uint32_t z_order) {
		m_z_order = z_order;
	}

	uint8_t Sprite::flip() {
		return m_flip;
	}

	void Sprite::flip(uint8_t flip) {
		m_flip = flip;
	}

	uint32_t Sprite::type() {
		return SPRITE_TYPE_UNKNOWN;
	}

	Rect* Sprite::renderable_source_rect() {
		return nullptr;
	}

	Rect* Sprite::renderable_destination_rect() {
		return nullptr;
	}

	Rect* Sprite::renderable_clip_rect() {
		return nullptr;
	}

	PointF* Sprite::renderable_center_frame() {
		return nullptr;
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