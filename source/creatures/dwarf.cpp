#include "dwarf.h"
#include "items\backpack.h"

using namespace creatures;
using namespace items;

CDwarf::CDwarf()
{
   storage.reset( new CBackPack );
}

TCreatureType CDwarf::getCreatureType() const
{
   return TCreatureType::dwarf;
}

std::string creatures::CDwarf::getName() const
{
   return "Dwarf";
}
