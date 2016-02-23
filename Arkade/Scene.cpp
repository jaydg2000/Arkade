#include "Scene.h"

namespace arkade {

	Scene::Scene()
	{
		m_scene_is_ended = false;
	}


	Scene::~Scene()
	{
	}

	void Scene::run() {
		on_setup();
		on_begin();
		while (!m_scene_is_ended) {
			check_keybaord_input();
			check_mouse_input();
			check_sprite_collisions();
			on_loop();
			send_messages();
			update_sprites();
			render_all();
		}
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

	void Scene::check_keybaord_input() {

	}
	
	void Scene::check_mouse_input() {

	}

	void Scene::check_sprite_collisions() {

	}

	void Scene::send_messages() {

	}

	void Scene::update_sprites() {

	}

	void Scene::render_all() {

	}

}