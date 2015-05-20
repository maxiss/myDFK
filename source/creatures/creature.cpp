#include "creature.h"
#include "items\containerPosition.h"
#include "items\backpack.h"

using namespace creatures;
using namespace items;

objects::TObjectType ICreature::getObjectType() const
{
   return objects::TObjectType::creature;
}

IItem::Ptr ICreature::getItem()
{
   if ( storage )
      return storage->get();
   else
      return nullptr;
}

void ICreature::carryItem( IItem::Ptr item )
{
   if ( storage )
      storage->store( item );
}

