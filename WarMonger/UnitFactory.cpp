#include <TextureCache.h>
#include "UnitFactory.h"

#define TEXTURE_UNIT_INFANTRY            "res/unit_infantry.png"
#define TEXTURE_UNIT_MECH_INFANTRY       "res/unit_mech_infantry.png"

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

Unit* UnitFactory::_make_infantry()
{
    auto unit_sprite = new Sprite(TEXTURE_UNIT_INFANTRY, make_size(32, 32));
    unit_sprite->use_screen_positioning(true);
    TerrainCosts* costs = new TerrainCosts(1, 2, 3, 2);
    Unit* unit = new Unit(UNIT_INFANTRY, RGB::White, unit_sprite, costs);
    return unit;
}

Unit* UnitFactory::_make_mechanized_infantry()
{
    auto unit_sprite = new Sprite(TEXTURE_UNIT_MECH_INFANTRY, make_size(32, 32));
    unit_sprite->use_screen_positioning(true);
    TerrainCosts* costs = new TerrainCosts(1, 2, -1, 2);
    Unit* unit = new Unit(UNIT_MECHANIZED_INFANTRY, RGB::White, unit_sprite, costs);
    return unit;
}
