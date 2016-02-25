#include "Scene.h"

namespace arkade {

	Scene::Scene() {
		Scene(new BoundingBoxCollisionDetector());
	}

	Scene::Scene(CollisionDetector* collision_detector) {
		m_scene_is_ended = false;
		m_collision_detector = collision_detector;
		m_auto_collision_detection_enabled = false;
	}


	Scene::~Scene() {		
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

	void Scene::enable_auto_collision_detection(bool enabled) {
		m_auto_collision_detection_enabled = enabled;
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

	void Scene::auto_detect_collisions(CollisionDetector* detector) {
		ACQUIRE_SPR_REG(ptr_sprite_reg);
		ptr_sprite_reg->for_each([detector, ptr_sprite_reg](Sprite* s1) {
			ptr_sprite_reg->for_each([detector, s1](Sprite* s2) {
				if(s1!=s2)
					detector->detect(s1, s2);
			});
		});
	}

	void Scene::on_detect_collisions(CollisionDetector* detector) {				
	}

	void Scene::setup_sprites() {
		ACQUIRE_SPR_REG(ptr_sprite_reg);
		ptr_sprite_reg->for_each([](Sprite* s){ s->on_setup(); });
	}

	void Scene::cleanup_sprites() {
		ACQUIRE_SPR_REG(ptr_sprite_reg);
		ptr_sprite_reg->for_each([](Sprite* s){ s->on_cleanup(); });
	}

	void Scene::update_sprites() {
		ACQUIRE_SPR_REG(ptr_sprite_reg);
		ptr_sprite_reg->for_each([](Sprite* s){ s->on_update(); });
	}

	void Scene::render_sprites() {
		Graphics* graphics = Graphics::instance();
		ACQUIRE_SPR_REG(ptr_sprite_reg);
		
		graphics->begin_render();

		ptr_sprite_reg->for_each([graphics](Sprite* sprite) {
			sprite->on_pre_render();
			graphics->render(sprite);
			sprite->on_post_render();
		});

		graphics->end_render();
	}

	void Scene::handle_messages() {
		ACQUIRE_SPR_REG(ptr_sprite_reg);
		ptr_sprite_reg->for_each([](Sprite* sprite) {
			sprite->flush();
		});
	}

}