#include "creature.h"
#include "map\mapPosition.h"

using namespace game_engine;

ObjectType ICreature::getObjectType() const
{
   return ObjectType::Creature;
}

void ICreature::carryItem( IItem::Ptr item )
{
   auto storage = getStorage();
   if ( storage )
      storage->store( item );
}

ItemList ICreature::getEquipedItems()
{
   ItemList items;
   for ( auto it : slots )
   {
      auto item = it->getItem();
      if ( item )
         items.push_back( item );
   }
   return items;
}

void ICreature::move( Coord dx, Coord dy )
{
   if ( position && position->getPositionType() == PositionType::Map  )
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

ItemList ICreature::getStorageItems()
{
   auto storage = getStorage();
   if ( storage )
      return storage->getItems();
   else
      return ItemList();
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
