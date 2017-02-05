#pragma once
#include <ArkadeTypes.h>

#define SCORE_PATH_ORG_NAME "Jay Green"
#define SCORE_PATH_APP_NAME "Franky Fish"

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

