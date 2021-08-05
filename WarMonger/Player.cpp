#include "Player.h"

Player::Player()
{
    _units = new vector<Unit*>();
    _occupied_cities = new vector<City*>();
    _color = RGB::Blue;
}

Player::~Player()
{
    if (_units)
    {
        for (Unit* unit : *_units)
        {
            delete unit;
        }
        delete _units;
    }
}

bool Player::is_ai()
{
    return _is_ai;
}

void Player::add_unit(Unit* unit)
{
    unit->color(_color);
    _units->push_back(unit);
}

void Player::remove_unit(Unit* unit)
{   
    int32_t index = find_unit_index(unit);
    if (index > -1)
        _units->erase(_units->begin()+index);
}

vector<Unit*>* Player::units()
{
    return _units;
}

RGB Player::color()
{
    return _color;
}

void Player::color(RGB color)
{
    _color = color;
}

int32_t Player::find_unit_index(Unit* unit)
{
    uint32_t index = 0;
    for (Unit* item : *_units)
    {
        if (item == unit)
            return index;
        index++;
    }
    return -1;
}

int32_t Player::find_city_index(City* city)
{
    uint32_t index = 0;
    for (City* item : *_occupied_cities)
    {
        if (item == city)
            return index;
        index++;
    }
    return -1;
}

void Player::take_city(City* city)
{
    city->back_color(_color);
    _occupied_cities->push_back(city);    
}

void Player::release_city(City* city)
{
    uint32_t index = find_city_index(city);
    if (index > -1)
        _occupied_cities->erase(_occupied_cities->begin()+index);
}

bool Player::occupies_city(City* city)
{
    return find_city_index(city) > -1;
}
