#include "creature.h"
#include "map\mapPosition.h"

using namespace creatures;
using namespace items;
using namespace objects;
using namespace gamemap;

TObjectType ICreature::getObjectType() const
{
   return TObjectType::creature;
}

IItem::Ptr ICreature::getItem()
{
   auto package = getPackage();
   if ( package )
      return package->get();
   else
      return nullptr;
}

void ICreature::carryItem( IItem::Ptr item )
{
   auto package = getPackage();
   if ( package )
      package->store( item );
}

void ICreature::move( coord dx, coord dy )
{
   if ( position && position->getPositionType() == TPositionType::map  )
   {
      auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
      auto coords = mapPosition->getCoords();
      coords.x += dx;
      coords.y += dy;
      mapPosition->setCoords( coords );
   }
}

void creatures::ICreature::equip( items::IItem::Ptr item )
{
   for ( auto it : slots )
   {
      if ( it->canEquip( item ) )
      {
         it->equip( item );
         break;
      }
   }

}

void creatures::ICreature::addSlot( CEquipmentSlot::Ptr slot )
{
   slots.push_back( slot );
}

void creatures::ICreature::setPackageSlot( CEquipmentSlot::Ptr slot )
{
   packageSlot = slot;
}

CItemContainer::Ptr creatures::ICreature::getPackage()
{
   auto slot = packageSlot.lock();
   if ( !slot )
      return nullptr;

   return std::dynamic_pointer_cast<CItemContainer>( slot->getItem() );
}
