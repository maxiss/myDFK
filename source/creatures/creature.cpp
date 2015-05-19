#include "creature.h"
#include "items\containerPosition.h"

using namespace creatures;
using namespace items;

ICreature::ICreature()
   : backpack{ new CItemContainer }
{}

objects::TObjectType ICreature::getObjectType() const
{
   return objects::TObjectType::creature;
}

IItem::Ptr ICreature::getItem()
{
   return backpack->get();
}

void ICreature::carryItem( IItem::Ptr item )
{
   item->setPosition( std::make_shared<CContainerPosition>( item, backpack ) );
}

