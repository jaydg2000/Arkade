#pragma once
#include <vector>
#include "Unit.h"

using namespace std;

class Player
{
public:
	Player();
	~Player();

	bool						is_ai();	
	vector<Unit*>*				units();
private:
	bool						_is_ai;
	vector<Unit*>*				_units;
};

