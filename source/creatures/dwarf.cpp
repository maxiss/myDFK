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
