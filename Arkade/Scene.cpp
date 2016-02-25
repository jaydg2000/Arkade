#include "Scene.h"

namespace arkade {

	Scene::Scene()
	{
		m_scene_is_ended = false;
		m_collision_detector = new BoundingBoxCollisionDetector();
	}

	Scene::Scene(CollisionDetector* collision_detector) {
		m_scene_is_ended = false;
		m_collision_detector = collision_detector;
	}


	Scene::~Scene()
	{
	}

	void Scene::run() {
		on_setup();
		setup_sprites();
		on_begin();
		while (!m_scene_is_ended) {
			check_keyboard_input();
			check_mouse_input();
			on_loop();
			on_detect_collisions(m_collision_detector);
			handle_messages();
			update_sprites();
			render_sprites();
		}
		cleanup_sprites();
		on_cleanup();
	}

	void Scene::stop() {
		m_scene_is_ended = true;
	}

	void Scene::on_setup() {

	}

	void Scene::on_begin() {
	}

	void Scene::on_loop() {
	}

	void Scene::on_end() {
	}
	
	void Scene::on_cleanup() {
	}

	void Scene::check_keyboard_input() {

	}
	
	void Scene::check_mouse_input() {

	}

	void Scene::on_detect_collisions(CollisionDetector* detector) {				
	}

	void Scene::setup_sprites() {
		__arkade_spr_registry* ptr_sprite_reg = __arkade_spr_registry::instance();
		ptr_sprite_reg->for_each([](Sprite* s){ s->on_setup(); });
	}

	void Scene::cleanup_sprites() {
		__arkade_spr_registry* ptr_sprite_reg = __arkade_spr_registry::instance();
		ptr_sprite_reg->for_each([](Sprite* s){ s->on_cleanup(); });
	}

	void Scene::update_sprites() {
		__arkade_spr_registry* ptr_sprite_reg = __arkade_spr_registry::instance();
		ptr_sprite_reg->for_each([](Sprite* s){ s->on_update(); });
	}

	void Scene::render_sprites() {
		Graphics* graphics = Graphics::instance();
		__arkade_spr_registry* ptr_sprite_reg = __arkade_spr_registry::instance();
		
		graphics->begin_render();

		ptr_sprite_reg->for_each([graphics](Sprite* sprite) {
			sprite->on_pre_render();
			graphics->render(sprite);
			sprite->on_post_render();
		});

		graphics->end_render();
	}

	void Scene::handle_messages() {
		__arkade_spr_registry* ptr_sprite_reg = __arkade_spr_registry::instance();
		ptr_sprite_reg->for_each([](Sprite* sprite) {
			sprite->flush();
		});
	}

}