#include "Player.h"

Player::Player()
{
    _units = new vector<Unit*>();
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

vector<Unit*>* Player::units()
{
    return _units;
}
