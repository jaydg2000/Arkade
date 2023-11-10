#include "Sprite.h"
#include "TextureCache.h"
#include "MathUtil.h"

namespace arkade {

	Sprite::Sprite()
	{
		m_type = SPRITE_TYPE_UNKNOWN;

		m_bounds_lower_x =
			m_bounds_lower_y =
			m_bounds_upper_x =
			m_bounds_upper_y = -1;

		m_rotation = 0;
		m_scale_x = 1.0f;
		m_scale_y = 1.0f;

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

		m_speed = 0.0f;
		m_velocity_x = 0.0f;
		m_velocity_y = 0.0f;
		m_friction_magnitude = .0050f;
		m_acceleration_magnitude = .0050f;
		m_acceleration_maximum = 1.0f;

		m_use_screen_positioning = false;
		m_is_visible = true;
		m_use_physics - false;

		m_is_attached = false;
		m_attached_relative_x = m_attached_relative_y = 0.0f;
	}

	Sprite::Sprite(const char* filename, const Size& frame_size) : Sprite() {		
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

	Texture* Sprite::texture(Texture* ptr_texture) {
		Texture* ptr_existing_texture = m_ptr_texture;
		m_ptr_texture = ptr_texture;
		return ptr_existing_texture;
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

	bool Sprite::use_screen_positioning() {
		return m_use_screen_positioning;
	}

	void Sprite::use_screen_positioning(bool enabled) {
		m_use_screen_positioning = enabled;
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

		m_source_rect.w = m_frame_size.x;
		m_source_rect.h = m_frame_size.y;
	}

	uint32_t Sprite::z_order() {
		return m_z_order;
	}

	void Sprite::z_order(uint32_t z_order) {
		m_z_order = z_order;
	}

	void Sprite::scale(float scale_x, float scale_y) {
		m_scale_x = scale_x;
		m_scale_y = scale_y;
	}
	
	float Sprite::scale_x() {
		return m_scale_x;
	}

	float Sprite::scale_y() {
		return m_scale_y;
	}

	Flip Sprite::flip() {
		return m_flip;
	}

	void Sprite::flip(Flip flip) {
		m_flip = flip;
	}

	uint32_t Sprite::type() {
		return m_type;
	}

	void Sprite::type(uint32_t type) {
		m_type = type;
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

	Rect Sprite::collision_rect() {
		destination_rect();
		Rect coll_rect;
		coll_rect.x = m_destination_rect.x;
		coll_rect.y = m_destination_rect.y;
		coll_rect.w = m_destination_rect.w * m_scale_x;
		coll_rect.h = m_destination_rect.h * m_scale_y;
		return coll_rect;
	}

	Point* Sprite::center_frame() {
		return &m_frame_center;
	}

	bool Sprite::intersects_with(uint32_t x, uint32_t y) {
		const Rect rect = make_rect(x, y, 1, 1);
		return (SDL_HasIntersection(&rect, &(collision_rect())) == SDL_TRUE);		
	}

	void Sprite::on_setup() {
	}

	void Sprite::on_cleanup() {
	}

	void Sprite::on_update() {
		if (m_use_physics) {
			move_relative_x(m_velocity_x);
			move_relative_y(m_velocity_y);
		}
		if (!m_attached_sprites.empty()) {
			for (auto spr : m_attached_sprites) {

			}
		}
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

	void Sprite::on_attached(float rel_x, float rel_y) {
		m_attached_relative_x = rel_x;
		m_attached_relative_y = rel_y;
		m_is_attached = true;
	}

	void Sprite::on_detached() {
		m_is_attached = false;
	}

	void Sprite::use_physics(bool enabled) {
		m_use_physics = enabled;
	}

	void Sprite::friction(float friction) {
		m_friction_magnitude = friction;
	}

	void Sprite::acceleration(float magnitude, float max) {
		m_acceleration_magnitude = magnitude;
		m_acceleration_maximum = max;
	}

	void Sprite::accelerate() {

		if (m_speed < m_acceleration_maximum)
			m_speed += m_acceleration_magnitude;

		float heading = rotation();
		m_movementHeadingInRadians = MathUtil::degrees_to_radians(heading);
		m_velocity_y += -(m_speed * cos(m_movementHeadingInRadians));
		m_velocity_x += m_speed * sin(m_movementHeadingInRadians);
	}

	void Sprite::apply_friction() {
		m_speed = 0.0f;

		if (m_velocity_x < 0) {
			m_velocity_x += m_friction_magnitude;
			if (m_velocity_x > 0)
				m_velocity_x = 0;
		}
		if (m_velocity_x > 0) {
			m_velocity_x -= m_friction_magnitude;
			if (m_velocity_x < 0)
				m_velocity_x = 0;
		}

		if (m_velocity_y < 0) {
			m_velocity_y += m_friction_magnitude;
			if (m_velocity_y > 0)
				m_velocity_y = 0;
		}
		if (m_velocity_y > 0) {
			m_velocity_y -= m_friction_magnitude;
			if (m_velocity_y < 0)
				m_velocity_y = 0;
		}
	}

	void Sprite::stop() {
		m_speed = 0;
		m_velocity_x = 0;
		m_velocity_y = 0;
		rotation(0);
	}

	void Sprite::tag(uint32_t val) {
		m_tags.emplace_back(val);
	}

	bool Sprite::has_tag(uint32_t val)
	{
		for (uint32_t t : m_tags) {
			if (t == val)
				return true;
		}
		return false;
	}

	void Sprite::attach_sprite(Sprite* sprite, float rel_x, float rel_y) {
		sprite->on_attached(rel_x, rel_y);
		m_attached_sprites.emplace_back(sprite);
	}

	void Sprite::detach_sprite(Sprite* sprite) {		
		auto iter = std::find(m_attached_sprites.begin(), m_attached_sprites.end(), sprite);
		if (iter != m_attached_sprites.end()) {
			m_attached_sprites.erase(iter);
			sprite->on_detached();
		}
	}
}