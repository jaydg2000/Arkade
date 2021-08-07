#include "UnitSpecification.h"
#include "Unit.h"

#define TEXTURE_UNIT_INFANTRY            "res/unit_infantry.png"
#define TEXTURE_UNIT_MECH_INFANTRY       "res/unit_mech_infantry.png"


UnitSpecification UnitSpecification::Infantry;
UnitSpecification UnitSpecification::MechanizedInfantry;

void UnitSpecification::init()
{
	UnitSpecification::Infantry._category = CATEGORY_LAND;
	UnitSpecification::Infantry._production_cost = 5;
	UnitSpecification::Infantry._maintenance_per_turn = 1;
	UnitSpecification::Infantry._firepower = 2;
	UnitSpecification::Infantry._strength = 3;
	UnitSpecification::Infantry._sentry_strength = 5;
	UnitSpecification::Infantry._attack_range = 1;		
	UnitSpecification::Infantry._attack_profile.can_attack_air = false;
	UnitSpecification::Infantry._attack_profile.can_attack_land = true;
	UnitSpecification::Infantry._attack_profile.can_attack_sea = false;
	UnitSpecification::Infantry._movement_profile._land = 3;
	UnitSpecification::Infantry._movement_profile._forest = 2;
	UnitSpecification::Infantry._movement_profile._mountain = 1;
	UnitSpecification::Infantry._movement_profile._river = 2;
	UnitSpecification::Infantry._movement_profile._water = 0;
	UnitSpecification::Infantry._unit_sprite = new Sprite(TEXTURE_UNIT_INFANTRY, make_size(32, 32));
	UnitSpecification::Infantry._unit_sprite->use_screen_positioning(true);

	UnitSpecification::MechanizedInfantry._category = CATEGORY_LAND;
	UnitSpecification::MechanizedInfantry._production_cost = 7;
	UnitSpecification::MechanizedInfantry._maintenance_per_turn = 2;
	UnitSpecification::MechanizedInfantry._firepower = 4;
	UnitSpecification::MechanizedInfantry._strength = 5;
	UnitSpecification::MechanizedInfantry._sentry_strength = 8;
	UnitSpecification::MechanizedInfantry._attack_range = 2;
	UnitSpecification::MechanizedInfantry._attack_profile.can_attack_air = true;
	UnitSpecification::MechanizedInfantry._attack_profile.can_attack_land = true;
	UnitSpecification::MechanizedInfantry._attack_profile.can_attack_sea = false;
	UnitSpecification::MechanizedInfantry._movement_profile._land = 4;
	UnitSpecification::MechanizedInfantry._movement_profile._forest = 1;
	UnitSpecification::MechanizedInfantry._movement_profile._mountain = 0;
	UnitSpecification::MechanizedInfantry._movement_profile._river = 1;
	UnitSpecification::MechanizedInfantry._movement_profile._water = 0;
	UnitSpecification::MechanizedInfantry._unit_sprite = new Sprite(TEXTURE_UNIT_MECH_INFANTRY, make_size(32, 32));
	UnitSpecification::MechanizedInfantry._unit_sprite->use_screen_positioning(true);
}


