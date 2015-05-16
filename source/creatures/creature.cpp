#include "creature.h"

using namespace creatures;
using namespace items;
//using namespace gamemap;

TObjectType ICreature::getObjectType() const
{
   return TObjectType::creature;
}

IItem::Ptr ICreature::getItem()
{
   if ( !itemContainer.empty() )
      return itemContainer.begin()->second;
   else
      return nullptr;
}

void ICreature::carryItem( IItem::Ptr item )
{
   // itemContainer.insert( item ); // !!! make interface like this
   item->setPosition( nullptr );
   itemContainer[ item.get() ] = item;
}

void ICreature::dropItem( IItem::Ptr item )
{
   itemContainer.erase( item.get() );
}
