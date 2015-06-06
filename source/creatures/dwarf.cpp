#include "dwarf.h"
#include "items\backpack.h"
#include "simpleSlot.h"

using namespace game_engine;

CDwarf::CDwarf()
{
   auto slot = std::make_shared<CSimpleSlot>( ItemType::Backpack );
   addSlot( slot );
   setStorageSlot( slot );

   addSlot( std::make_shared<CSimpleSlot>( ItemType::Weapon ) );
}

CreatureType CDwarf::getCreatureType() const
{
   return CreatureType::Dwarf;
}

std::string CDwarf::getName() const
{
   return "Dwarf";
}
