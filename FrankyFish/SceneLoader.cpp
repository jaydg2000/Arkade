#include "SceneLoader.h"
#include "Scene1SpriteData.h"


SceneLoader::SceneLoader()
{
}


SceneLoader::~SceneLoader()
{
}

void SceneLoader::read_file() {
	int* dptr = scene_sprite_data;

	for (int count = 0; count < SPRITES_LENGTH; count++) {
		int item_type = *dptr;
		int item_x = *(dptr + 1);
		int item_y = *(dptr + 2);

		dptr += 3;

		Sprite* rewardSprite = make_gamesprite(item_type, item_x, item_y);
		m_list_gamesprites.push_back(rewardSprite);
	}
}

void SceneLoader::clear_gameitems() {
	while (!m_list_gamesprites.empty()) {
		Sprite* sprite = m_list_gamesprites.front();
		m_list_gamesprites.pop_front();
		delete sprite;
	}
	m_list_gamesprites.clear();
}

list<Sprite*> SceneLoader::load_gameitems() {
	clear_gameitems();
	read_file();
	return m_list_gamesprites;
}

Sprite* SceneLoader::make_gamesprite(int type, int x, int y) {

	GameSprite* sprite;

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
	case ITEM_JELLY_FISH:
		sprite = new JellyFishSprite();
		break;
	case ITEM_BOULDER:
		sprite = new BoulderSprite();
		break;
	case ITEM_SPIKE:
		sprite = new SpikeSprite();
		break;
	case ITEM_COIN:
		sprite = new CoinSprite();
		break;
	case ITEM_HEART:
		sprite = new HeartSprite();
		break;
	}

	sprite->start_position(x, y);
	return sprite;
}