#pragma once
#include <ArkadeTypes.h>
#include "FileStorage.h"

class ScoreKeeper
{
public:
	ScoreKeeper();
	~ScoreKeeper();

	void				save(uint32_t score);
	uint32_t			read();

private:
	char*				build_full_path();
};

