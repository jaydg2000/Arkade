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

			Sprite* rewardSprite = make_gamesprite(item_type, item_x, item_y);
			m_list_gamesprites.push_back(rewardSprite);
		}
	}
	file.close();
}

void SceneRepository::reload_gameitems() {
	while (!m_list_gamesprites.empty()) {
		Sprite* sprite = m_list_gamesprites.front();
		m_list_gamesprites.pop_front();
		delete sprite;
	}

	read_file(m_psz_filename);
}

list<Sprite*> SceneRepository::load_gameitems() {
	return m_list_gamesprites;
}

Sprite* SceneRepository::make_gamesprite(int type, int x, int y) {

	Sprite* sprite;

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
		case ITEM_BUG_1:
			sprite = new FlyingBugSprite("res/sprites/sprite_bug_1.png", make_size(120, 95));
			sprite->animator(new ForwardAnimator(5, 50));
			sprite->animator()->current_frame(Random::rand_int(0, 4));
			break;
		case ITEM_BUG_2:
			sprite = new FlyingBugSprite("res/sprites/sprite_bug_2.png", make_size(118, 99));
			sprite->animator(new ForwardAnimator(7, 50));
			sprite->animator()->current_frame(Random::rand_int(0, 6));
			break;
		case ITEM_BUG_3:
			sprite = new FlyingBugSprite("res/sprites/sprite_bug_3.png", make_size(79, 80));
			sprite->animator(new ForwardAnimator(7, 50));
			sprite->animator()->current_frame(Random::rand_int(0, 6));
			break;
		case ITEM_COIN:
			sprite = new CoinSprite();
			break;
	}

	sprite->position(x, y);
	return sprite;
}
