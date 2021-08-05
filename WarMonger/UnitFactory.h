#pragma once
#include <ArkadeTypes.h>
#include <SpritePool.h>
#include <Sprite.h>
#include "Unit.h"

class UnitFactory
{
public:
	UnitFactory();
	~UnitFactory();

	Unit*					create_unit(uint32_t type_id);

private:
	Unit*					_make_infantry();
	Unit*					_make_mechanized_infantry();
};

