#pragma once
#include <ArkadeTypes.h>
#include <Sprite.h>
#include "AttackProfile.h"
#include "TerrainCosts.h"

using namespace arkade;

class UnitSpecification
{
public:
	UnitSpecification() {};
	~UnitSpecification() {};

	uint8_t					_firepower;
	uint8_t					_strength;
	uint8_t					_sentry_strength;
	uint8_t					_attack_range;
	uint8_t					_category;
	uint8_t					_production_cost;
	uint8_t					_maintenance_per_turn;
	AttackProfile 			_attack_profile;
	TerrainCosts 			_movement_profile;
	Sprite*					_unit_sprite;

	static UnitSpecification Infantry;
	static UnitSpecification MechanizedInfantry;

	static void				init();
};

