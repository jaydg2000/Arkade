#include "stdafx.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

#include "SceneRepository.h"

using namespace std;

SceneRepository::SceneRepository(const char* filename)
{	
	m_psz_filename = filename;
	read_file(m_psz_filename);
}


SceneRepository::~SceneRepository()
{
}

void SceneRepository::read_file(const char* filename) {
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		while (!file.eof()) {
			file >> line;
			istringstream ss(line);
			string part;

			getline(ss, part, ',');
			int item_type = atoi(part.c_str());
			getline(ss, part, ',');
			int item_x = atoi(part.c_str());
			getline(ss, part, ',');
			int item_y = atoi(part.c_str());

			if (item_type == ITEM_BUG_1
				|| item_type == ITEM_BUG_2
				|| item_type == ITEM_BUG_3) {

				Sprite* rewardSprite = make_reward(item_type, item_x, item_y);
				m_list_rewards_sprites.push_back(rewardSprite);
			}
			else if (item_type == ITEM_COIN) {
				Sprite* coin = make_coin(item_type, item_x, item_y);
				m_list_coin_sprites.push_back(coin);
			}
			else {
				Sprite* predatorSprite = make_predator(item_type, item_x, item_y);
				m_list_bad_fish_sprites.push_back(predatorSprite);
			}
		}
	}
	file.close();
}

void SceneRepository::reload_fish() {
	while (!m_list_bad_fish_sprites.empty()) {
		Sprite* sprite = m_list_bad_fish_sprites.front();
		m_list_bad_fish_sprites.pop_front();
		delete sprite;
	}

	while (!m_list_rewards_sprites.empty()) {
		Sprite* sprite = m_list_rewards_sprites.front();
		m_list_rewards_sprites.pop_front();
		delete sprite;
	}

	while (!m_list_coin_sprites.empty()) {
		Sprite* sprite = m_list_coin_sprites.front();
		m_list_coin_sprites.pop_front();
		delete sprite;
	}

	read_file(m_psz_filename);
}

list<Sprite*> SceneRepository::load_bad_fish() {
	return m_list_bad_fish_sprites;
}

list<Sprite*> SceneRepository::load_rewards() {
	return m_list_rewards_sprites;
}

list<Sprite*> SceneRepository::load_coins() {
	return m_list_coin_sprites;
}

Sprite* SceneRepository::make_predator(int type, int x, int y) {

	PredatorSprite* sprite;

	switch (type) {
		case ITEM_SHARK:
			sprite = new PredatorSprite("res/sprites/sprite_shark.png", make_size(406,227));
			sprite->animator(new ForwardAnimator(6, 80));
			sprite->animator()->current_frame(Random::rand_int(0,5));
			break;
		case ITEM_TOOTHY_FISH_1:
			sprite = new PredatorSprite("res/sprites/sprite_toothy_fish_1.png", make_size(75, 52));
			sprite->animator(new ForwardAnimator(16, 90));
			sprite->animator()->current_frame(Random::rand_int(0, 15));
			break;
		case ITEM_TOOTHY_FISH_2:
			sprite = new PredatorSprite("res/sprites/sprite_toothy_fish_2.png", make_size(79, 68));
			sprite->animator(new ForwardAnimator(6, 110));
			sprite->animator()->current_frame(Random::rand_int(0, 5));
			break;
		case ITEM_TOOTHY_FISH_3:
			sprite = new PredatorSprite("res/sprites/sprite_toothy_fish_3.png", make_size(234, 54));
			sprite->animator(new ForwardAnimator(7, 100));
			sprite->animator()->current_frame(Random::rand_int(0, 6));
			break;
		case ITEM_BUG_1:
			sprite = new PredatorSprite("res/sprites/sprite_bug_1.png", make_size(120, 95));
			sprite->animator(new ForwardAnimator(5, 30));
			sprite->animator()->current_frame(Random::rand_int(0, 4));
			break;
		case ITEM_BUG_2:
			sprite = new PredatorSprite("res/sprites/sprite_bug_2.png", make_size(118, 99));
			sprite->animator(new ForwardAnimator(7, 30));
			sprite->animator()->current_frame(Random::rand_int(0, 6));
			break;
		case ITEM_BUG_3:
			sprite = new PredatorSprite("res/sprites/sprite_bug_3.png", make_size(79, 80));
			sprite->animator(new ForwardAnimator(7, 30));
			sprite->animator()->current_frame(Random::rand_int(0, 6));
			break;
		case ITEM_COIN:
			sprite = new PredatorSprite("res/sprites/sprite_coin.png", make_size(66, 65));
			sprite->animator(new ForwardAnimator(6, 90));
			sprite->animator()->current_frame(Random::rand_int(0, 5));
			break;
		case ITEM_CRAB:
			sprite = new PredatorSprite("res/sprites/sprite_crab.png", make_size(74, 68));
			sprite->animator(new ForwardAnimator(16, 100));
			sprite->animator()->current_frame(Random::rand_int(0, 15));
			break;
		case ITEM_BIRD:
			sprite = new PredatorSprite("res/sprites/sprite_bird3.png", make_size(300, 370));
			sprite->animator(new ForwardAnimator(12, 50));
			sprite->animator()->current_frame(Random::rand_int(0, 11));
			break;
	}

	sprite->position(x, y);
	return sprite;
}

Sprite* SceneRepository::make_reward(int type, int x, int y) {

	Sprite* sprite;

	switch (type) {
		case ITEM_BUG_1:
			sprite = new SwimmingSprite("res/sprites/sprite_bug_1.png", make_size(120, 95));
			sprite->animator(new ForwardAnimator(5, 50));
			sprite->animator()->current_frame(Random::rand_int(0, 4));
			break;
		case ITEM_BUG_2:
			sprite = new SwimmingSprite("res/sprites/sprite_bug_2.png", make_size(118, 99));
			sprite->animator(new ForwardAnimator(7, 50));
			sprite->animator()->current_frame(Random::rand_int(0, 6));
			break;
		case ITEM_BUG_3:
			sprite = new SwimmingSprite("res/sprites/sprite_bug_3.png", make_size(79, 80));
			sprite->animator(new ForwardAnimator(7, 50));
			sprite->animator()->current_frame(Random::rand_int(0, 6));
			break;
	}

	sprite->position(x, y);
	return sprite;
}

Sprite* SceneRepository::make_coin(int type, int x, int y) {
	Sprite* sprite = new CoinSprite("res/sprites/sprite_coin.png", make_size(66, 65));
	return sprite;
}

