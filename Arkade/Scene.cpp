#include "Scene.h"

namespace arkade {

	Scene::Scene() {
		m_scene_is_ended = false;
		m_is_updating_sprites = true;		
	}


	Scene::~Scene() {		
	}

	void Scene::millis_per_frame(uint32_t millis) {
		m_millis_per_frame = millis;
	}

	void Scene::run() {
		Graphics*		ptr_graphics = Graphics::instance();
		Audio*			ptr_audio = Audio::instance();
		TextureCache*	ptr_texture_cache = TextureCache::instance();
		InputManager*	ptr_inputManager = new InputManager();

		m_frame_timer.start(m_millis_per_frame);

		on_setup();
		setup_sprites();
		on_begin();
		while (!m_scene_is_ended) {
			//SDL_PumpEvents();
			ptr_inputManager->update();
			on_check_input(ptr_inputManager);
			handle_messages();
			on_update();
			on_detect_collisions();
			update_sprites();
			ptr_graphics->begin_render();
			on_render(ptr_graphics);
			ptr_graphics->end_render();
			while (!m_frame_timer.has_elapsed());
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

	void Scene::on_check_input(InputManager* ptr_keyboard) {
	}

	void Scene::on_update() {

	}

	void Scene::on_render(Graphics* ptr_graphics) {
	}

	void Scene::on_end() {
	}
	
	void Scene::on_cleanup() {
	}

	void Scene::disable_sprite_updates() {
		m_is_updating_sprites = false;
	}

	void Scene::enable_sprite_updates() {
		m_is_updating_sprites = true;
	}

	//void Scene::check_mouse_input() {
	//	SDL_Event event;
	//	while (SDL_PollEvent(&event)) {
	//		if (event.type == SDL_MOUSEBUTTONDOWN) {
	//			if (event.button.button == SDL_BUTTON_LMASK) {
	//			} 
	//			else if (event.button.button == SDL_BUTTON_RMASK) {
	//			}
	//		}
	//	}
	//}

	void Scene::on_detect_collisions() {				
	}

	void Scene::on_message(uint32_t message_type, MessageSink * ptr_sender, void * ptr_data) {
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
		if (!m_is_updating_sprites)
			return;

		for (Sprite* sprite : m_sprite_list) {
			sprite->on_update();
		}
	}

	void Scene::handle_messages() {
		flush();
		for (Sprite* sprite : m_sprite_list) {
			sprite->flush();
		}
	}

}