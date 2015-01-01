#include "creature.h"

using namespace creatures;
using namespace gamemap;

TObjectType CCreature::getObjectType() const
{
   return OBJ_TYPE_CREATURE;
}

void CCreature::carryItem( CItem* item )
{
   this->items.add( item );
}
