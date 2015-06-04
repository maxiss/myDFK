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

      virtual TObjectType getObjectType() const override final;
      virtual TCreatureType getCreatureType() const = 0;

      void move( coord dx, coord dy );

      void equip( IItem::Ptr );
      TItemList getEquipedItems();

      void carryItem( IItem::Ptr );
      TItemList getStorageItems();

   protected:
      void addSlot( CEquipmentSlot::Ptr );
      void setStorageSlot( CEquipmentSlot::Ptr );

   private:
      CItemContainer::Ptr getStorage();

   private:
      TEquipmentSlots slots;
      CEquipmentSlot::WeakPtr storageSlot;
   };
}
