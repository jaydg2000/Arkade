#include "SceneFrankysFirstSwim.h"



SceneFrankysFirstSwim::SceneFrankysFirstSwim()
{
}


SceneFrankysFirstSwim::~SceneFrankysFirstSwim()
{
}


void SceneFrankysFirstSwim::on_setup() {
	m_water_color_rgb.r = 0;
	m_water_color_rgb.g = 0;
	m_water_color_rgb.b = 100;
	m_franky_start_x = 125;
	m_franky_start_y = FishGame::res_height / 2;
	m_ptr_franky = new FrankySprite();	
	m_ptr_sky = new Image("res/sprites/sky.png", make_size(720, 400));
	
	this->register_sprite(m_ptr_franky);

	m_spritepool_predators = new SpritePool();
	m_spritepool_predators->add(new SharkSprite());
	m_spritepool_predators->obtain();
}

void SceneFrankysFirstSwim::on_begin() {
	
	m_ptr_franky->position(m_franky_start_x, m_franky_start_y);
}

void SceneFrankysFirstSwim::on_check_keyboard_input(Keyboard* ptr_keyboard) {
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_ESCAPE)) {
		stop();
	}
	if (ptr_keyboard->is_key_pressed(SDL_SCANCODE_UP)) {
		m_ptr_franky->swim();
	}
	else {
		m_ptr_franky->idle();
	}
}

void SceneFrankysFirstSwim::on_mouse_button(uint32_t button_event_type) {
}

void SceneFrankysFirstSwim::on_update() {
	m_spritepool_predators->for_each([] (Sprite* sprite) { ((PredatorSprite*)sprite)->swim(); });
}

void SceneFrankysFirstSwim::on_render(Graphics* ptr_graphics) {
	ptr_graphics->background_color(m_water_color_rgb);
	ptr_graphics->render(m_ptr_sky);
	ptr_graphics->render(m_ptr_franky);
	ptr_graphics->render(m_spritepool_predators);
}

void SceneFrankysFirstSwim::on_end() {

}

void SceneFrankysFirstSwim::on_cleanup() {
	delete m_ptr_franky;
	delete m_ptr_sky;
	delete m_spritepool_predators;
}

void SceneFrankysFirstSwim::on_detect_collisions() {

}

void SceneFrankysFirstSwim::on_message(uint32_t message_type, MessageSink* ptr_sender, void* ptr_data) {

}
