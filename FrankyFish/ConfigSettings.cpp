#include "ConfigSettings.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

ConfigSettings::ConfigSettings()
{
	m_is_sound_on = true;
	m_is_music_on = true;

	read();
}


ConfigSettings::~ConfigSettings()
{
}

void ConfigSettings::save(bool sound_on, bool music_on) {
	char* fullpath = build_full_path();

	if (fullpath) {
		ofstream file;
		file.open(fullpath, ios::trunc);

		char s, m;

		s = (sound_on ? '1' : '0');
		m = (music_on ? '1' : '0');

		file << s;
		file << m;
		file.close();
	}
}

bool ConfigSettings::is_sound_on() {
	return m_is_sound_on;
}

bool ConfigSettings::is_music_on() {
	return m_is_music_on;
}

void ConfigSettings::read() {
	char* fullpath = build_full_path();
	char s, m;
	if (fullpath) {
		ifstream file;		
		file.open(fullpath);
		file >> s;
		file >> m;
		file.close();

		m_is_sound_on = (s == '1');
		m_is_music_on = (m == '1');
	}
}

char* ConfigSettings::build_full_path() {
	char* path = SDL_GetPrefPath(SCORE_PATH_ORG_NAME, SCORE_PATH_APP_NAME);
	char fullpath[200] = { 0 };

	if (path) {
		strcpy(fullpath, path);
		strcat(fullpath, "franky_config.t");
	}

	return fullpath;
}