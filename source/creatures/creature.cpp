#include "creature.h"
#include "items\containerPosition.h"
#include "items\backpack.h"

using namespace creatures;
using namespace items;

ICreature::ICreature()
   : storage( new CBackPack )
{}

objects::TObjectType ICreature::getObjectType() const
{
   return objects::TObjectType::creature;
}

IItem::Ptr ICreature::getItem()
{
   if ( storage )
   {
      auto backpack = std::dynamic_pointer_cast<CBackPack>(storage);
      return backpack->get();
   }
   else
      return nullptr;
}

void ICreature::carryItem( IItem::Ptr item )
{
   if ( storage )
   {
      auto backpack = std::dynamic_pointer_cast<CBackPack>(storage);
      backpack->store( item );
   }
}

