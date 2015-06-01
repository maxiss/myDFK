#include "dwarf.h"
#include "items\backpack.h"
#include "simpleSlot.h"

using namespace creatures;
using namespace items;

CDwarf::CDwarf()
{
   auto slot = std::make_shared<CSimpleSlot>( TItemType::backpack );
   addSlot( slot );
   setStorageSlot( slot );

   addSlot( std::make_shared<CSimpleSlot>( TItemType::weapon ) );
}

TCreatureType CDwarf::getCreatureType() const
{
   return TCreatureType::dwarf;
}

std::string creatures::CDwarf::getName() const
{
   return "Dwarf";
}
