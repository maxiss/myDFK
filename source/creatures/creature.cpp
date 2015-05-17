#include "creature.h"
#include "items\containerPosition.h"

using namespace creatures;
using namespace items;

TObjectType ICreature::getObjectType() const
{
   return TObjectType::creature;
}

IItem::Ptr ICreature::getItem()
{
   return backpack->get();
}

void ICreature::carryItem( IItem::Ptr item )
{
   item->setPosition( std::make_shared<CContainerPosition>( item, backpack ) );
}

ICreature::ICreature()
   : backpack{ new CItemContainer }
{}
