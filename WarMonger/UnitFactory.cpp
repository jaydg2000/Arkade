#include <TextureCache.h>
#include <Random.h>
#include <string>
#include "UnitFactory.h"
#include "UnitSpecification.h"

UnitFactory::UnitFactory()
{
}

UnitFactory::~UnitFactory()
{
}

Unit* UnitFactory::create_unit(uint32_t type_id)
{
    auto texture_cache = TextureCache::instance();

    switch (type_id)
    {
        case UNIT_INFANTRY:
            return _make_infantry();
        case UNIT_MECHANIZED_INFANTRY:
            return _make_mechanized_infantry();
    }

}

string UnitFactory::_generate_unit_name(const char* suffix)
{
    int unit_number = Random::rand_int(1, 999);
    int digit = unit_number % 10;
    string rd;

    switch (digit)
    {
        case 1:
            rd.append("st");
            break;
        case 2:
            rd.append("nd");
            break;
        case 3:
            rd.append("rd");
            break;
        default:
            rd.append("th");
    }

    string name;    
    name.append(std::to_string(unit_number)).append(rd).append(" ").append(suffix);
    return name;
}

Unit* UnitFactory::_make_infantry()
{
    string unit_name = _generate_unit_name("Infantry");
    Unit* unit = new Unit(UNIT_INFANTRY, RGB::White, unit_name, &UnitSpecification::Infantry);
    return unit;
}

Unit* UnitFactory::_make_mechanized_infantry()
{
    string unit_name = _generate_unit_name("Mech Infantry");
    Unit* unit = new Unit(UNIT_MECHANIZED_INFANTRY, RGB::White, unit_name, &UnitSpecification::MechanizedInfantry);
    return unit;
}
