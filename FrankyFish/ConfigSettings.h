#pragma once
#include <ArkadeTypes.h>
#include "FileStorage.h"

class ConfigSettings
{
public:
	ConfigSettings();
	~ConfigSettings();

	void					save(bool sound_on, bool music_on);
	bool					is_sound_on();
	bool					is_music_on();

private:

	bool					m_is_sound_on;
	bool					m_is_music_on;

	void					read();
	char*					build_full_path();

};

