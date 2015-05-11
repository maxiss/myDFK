#include "creature.h"

using namespace creatures;
using namespace gamemap;

TObjectType CCreature::getObjectType() const
{
   return TObjectType::creature;
}

CItem* CCreature::getItem()
{
   return items.get();
}

void CCreature::carryItem( CItem* item )
{
   items.add( item );
}

void CCreature::dropItem( CItem* item )
{
   items.remove( item );
}
