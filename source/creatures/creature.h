#pragma once

#include "objects\IObject.h"
#include "creatureTypes.h"
#include "items\item.h"
#include "items\ItemContainer.h"
#include "equipmentSlot.h"

namespace game_engine
{
   class ICreature : public IObject
   {
   public:
      typedef std::shared_ptr< ICreature > Ptr;

      virtual ObjectType getObjectType() const override final;
      virtual CreatureType getCreatureType() const = 0;

      void move( Coord dx, Coord dy );

      void equip( IItem::Ptr );
      ItemList getEquipedItems();

      void carryItem( IItem::Ptr );
      ItemList getStorageItems();

   protected:
      void addSlot( CEquipmentSlot::Ptr );
      void setStorageSlot( CEquipmentSlot::Ptr );

   private:
      CItemContainer::Ptr getStorage();

   private:
      EquipmentSlots slots;
      CEquipmentSlot::WeakPtr storageSlot;
   };
}
