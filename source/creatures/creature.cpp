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

void ICreature::carryItem( IItem::Ptr item )
{
   auto storage = getStorage();
   if ( storage )
      storage->store( item );
}

TItemList ICreature::getEquipedItems()
{
   TItemList items;
   for ( auto it : slots )
   {
      auto item = it->getItem();
      if ( item )
         items.push_back( item );
   }
   return items;
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

void ICreature::equip( IItem::Ptr item )
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

TItemList ICreature::getStorageItems()
{
   auto storage = getStorage();
   if ( storage )
      return storage->getItems();
   else
      return TItemList();
}

void ICreature::addSlot( CEquipmentSlot::Ptr slot )
{
   slots.push_back( slot );
}

void ICreature::setStorageSlot( CEquipmentSlot::Ptr slot )
{
   storageSlot = slot;
}

CItemContainer::Ptr ICreature::getStorage()
{
   auto slot = storageSlot.lock();
   if ( !slot )
      return nullptr;

   return std::dynamic_pointer_cast<CItemContainer>( slot->getItem() );
}
