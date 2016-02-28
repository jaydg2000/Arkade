#include "Scene.h"

namespace arkade {

	Scene::Scene() {
		m_scene_is_ended = false;
	}


	Scene::~Scene() {		
	}

	void Scene::run() {
		Graphics* ptr_graphics = Graphics::instance();
		Audio* ptr_audio = Audio::instance();
		TextureCache* ptr_texture_cache = TextureCache::instance();
		Keyboard* ptr_keyboard = new Keyboard();

		on_setup();
		setup_sprites();
		on_begin();
		while (!m_scene_is_ended) {
			SDL_PumpEvents();
			check_mouse_input();
			on_check_keyboard_input(ptr_keyboard);
			on_mouse_input();
			handle_messages();
			on_update();
			on_detect_collisions();
			update_sprites();
			ptr_graphics->begin_render();
			on_render(ptr_graphics);
			ptr_graphics->end_render();
		}
		cleanup_sprites();
		on_cleanup();
	}

	void Scene::stop() {
		m_scene_is_ended = true;
	}

	void Scene::register_sprite(Sprite* sprite) {
		m_sprite_list.push_back(sprite);
	}

	void Scene::unregister_sprite(Sprite* sprite) {
		m_sprite_list.remove(sprite);
	}

	void Scene::register_sprite_pool(SpritePool* ptr_sprite_pool) {
		list<Sprite*>* sprite_list = ptr_sprite_pool->get_sprite_list();
		for (Sprite* sprite : *sprite_list) {
			register_sprite(sprite);
		}
	}

	void Scene::on_setup() {
	}

	void Scene::on_begin() {
	}

	void Scene::on_check_keyboard_input(Keyboard* ptr_keyboard) {
	}

	void Scene::on_mouse_input() {
	}

	void Scene::on_update() {

	}

	void Scene::on_render(Graphics* ptr_graphics) {
	}

	void Scene::on_end() {
	}
	
	void Scene::on_cleanup() {
	}

	void Scene::check_mouse_input() {
	}

	void Scene::on_detect_collisions() {				
	}

	void Scene::setup_sprites() {
		for (Sprite* sprite : m_sprite_list) {
			sprite->on_setup();
		}
	}

	void Scene::cleanup_sprites() {
		for (Sprite* sprite : m_sprite_list) {
			sprite->on_cleanup();
		}
	}

	void Scene::update_sprites() {
		for (Sprite* sprite : m_sprite_list) {
			sprite->on_update();
		}
	}

	void Scene::handle_messages() {
		for (Sprite* sprite : m_sprite_list) {
			sprite->flush();
		}
	}

}