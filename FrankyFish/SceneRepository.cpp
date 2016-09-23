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
}


SceneRepository::~SceneRepository()
{
}

void SceneRepository::read_file() {
	ifstream file(m_psz_filename);
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

void SceneRepository::clear_gameitems() {
	while (!m_list_gamesprites.empty()) {
		Sprite* sprite = m_list_gamesprites.front();
		m_list_gamesprites.pop_front();
		delete sprite;
	}
	m_list_gamesprites.clear();
}

list<Sprite*> SceneRepository::load_gameitems() {
	clear_gameitems();
	read_file();
	return m_list_gamesprites;
}

Sprite* SceneRepository::make_gamesprite(int type, int x, int y) {

	Sprite* sprite;

	switch (type) {
		case ITEM_SHARK:
			sprite = new SharkSprite();
			break;
		case ITEM_TOOTHY_FISH_1:
			sprite = new ToothyFishOneSprite();
			break;
		case ITEM_TOOTHY_FISH_2:
			sprite = new ToothyFishTwoSprite();
			break;
		case ITEM_TOOTHY_FISH_3:
			sprite = new ToothyFishThreeSprite();
			break;
		case ITEM_BIRD:
			sprite = new BirdSprite();
			break;
		case ITEM_BUG_1:
			sprite = new BugOneSprite();
			break;
		case ITEM_BUG_2:
			sprite = new BugTwoSprite();
			break;
		case ITEM_BUG_3:
			sprite = new BugThreeSprite();
			break;
		case ITEM_COIN:
			sprite = new CoinSprite();
			break;
	}

	sprite->position(x, y);
	return sprite;
}
