#include "ScoreKeeper.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

ScoreKeeper::ScoreKeeper()
{
}


ScoreKeeper::~ScoreKeeper()
{
}

void ScoreKeeper::save(uint32_t score) {
	char* fullpath = build_full_path();

	if (fullpath) {
		ofstream file;
		file.open(fullpath, ios::binary | ios::trunc);
		file << score;
		file.close();
	}
}

uint32_t ScoreKeeper::read() {	
	char* fullpath = build_full_path();
	uint32_t score = 0;

	if (fullpath) {
		ifstream file;
		file.open(fullpath, ios::binary);
		file >> score;
		file.close();
	}

	return score;
}

char* ScoreKeeper::build_full_path() {
	char* path = SDL_GetPrefPath(SCORE_PATH_ORG_NAME, SCORE_PATH_APP_NAME);
	char fullpath[200] = { 0 };

	if (path) {
		strcpy(fullpath, path);
		strcat(fullpath, "franky_score.b");
	}

	return fullpath;
}