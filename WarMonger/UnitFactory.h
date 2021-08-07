#pragma once
#include <ArkadeTypes.h>
#include <SpritePool.h>
#include <Sprite.h>
#include "Unit.h"

using namespace std;

class UnitFactory
{
public:
	UnitFactory();
	~UnitFactory();

	Unit*					create_unit(uint32_t type_id);

private:
	string					_generate_unit_name(const char* suffix);
	Unit*					_make_infantry();
	Unit*					_make_mechanized_infantry();
};

