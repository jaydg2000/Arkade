#include "Scene.h"

namespace arkade {

	Scene::Scene() {
		m_type = 0;
		m_scene_is_ended = false;
		m_game_is_ended = false;
		m_is_updating_sprites = true;	
		m_is_paused = false;
	}


	Scene::~Scene() {		
	}

	void Scene::type(uint32_t type) {
		m_type = type;
	}

	uint32_t Scene::type() {
		return m_type;
	}

	void Scene::show_mouse()
	{
		SDL_ShowCursor(1);
	}

	void Scene::hide_mouse()
	{
		SDL_ShowCursor(0);
	}

	void Scene::register_form(Form* form)
	{
		m_form_list.push_back(form);
	}

	void Scene::unregister_form(Form* form)
	{
		m_form_list.remove(form);
	}

	void* Scene::result()
	{
		return _result;
	}

	void Scene::millis_per_frame(uint32_t millis) {
		m_millis_per_frame = millis;
	}

	bool Scene::run() {
		Graphics*		ptr_graphics = Graphics::instance();
		Audio*			ptr_audio = Audio::instance();
		TextureCache*	ptr_texture_cache = TextureCache::instance();
		InputManager*	ptr_inputManager = new InputManager();

		m_frame_timer.start(m_millis_per_frame);

		on_setup();
		setup_sprites();
		on_begin();
		while (!m_scene_is_ended) {
			ptr_inputManager->update();
			on_check_input(ptr_inputManager);
			check_forms_input(ptr_inputManager);
			if (!m_is_paused) {
				handle_messages();
				on_detect_collisions();
				on_update();
				update_sprites();
				update_forms();
				ptr_graphics->begin_render();
				on_render(ptr_graphics);
				render_forms(ptr_graphics);
				ptr_graphics->end_render();
			}
			while (!m_frame_timer.has_elapsed());
		}
		cleanup_sprites();
		on_cleanup();

		return !m_game_is_ended;
	}

	void Scene::stop() {
		m_scene_is_ended = true;
		on_end();
	}

	void Scene::end() {
		m_game_is_ended = true;
		stop();
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

	void Scene::pause() {
		m_is_paused = true;
	}

	void Scene::resume() {
		m_is_paused = false;
	}

	bool Scene::is_paused() {
		return m_is_paused;
	}

	void Scene::on_detect_collisions() {				
	}

	void Scene::on_message(uint32_t message_type, MessageSink * ptr_sender, void * ptr_data) {
	}

	void Scene::result(void* ptr_result)
	{
		_result = ptr_result;
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
		for (Form* form : m_form_list) {
			form->flush();
		}
	}

	void Scene::update_forms()
	{
		for (Form* form : m_form_list) {
			form->on_update();
		}
	}

	void Scene::render_forms(Graphics* ptr_graphics)
	{
		for (Form* form : m_form_list)
		{
			if (form->visible())
			{
				form->on_render(ptr_graphics);
			}
		}
	}

	void Scene::check_forms_input(InputManager* ptr_input_manager)
	{
		for (Form* form : m_form_list)
		{
			if (form->enabled())
			{
				form->on_check_input(ptr_input_manager);
			}
		}
	}

}