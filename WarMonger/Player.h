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
	void						add_unit(Unit* unit);
	void						remove_unit(Unit* unit);
	vector<Unit*>*				units();
	RGB							color();
	void						color(RGB color);
	int32_t						find_unit_index(Unit* unit);
	void						take_city(City* city);
	void						release_city(City* city);
	bool						occupies_city(City* city);	
	int32_t						find_city_index(City* city);

private:
	bool						_is_ai;
	vector<Unit*>*				_units;
	vector<City*>*				_occupied_cities;
	RGB							_color;	
};


/*
 AI players will use a "closest city" algo to determine where to attack. 
 Will need algo to determine if ocean crossing is needed.
 Will need algo to determine how many armies to use in offensive.
 Will need algo to determine if naval forces are needed.
*/