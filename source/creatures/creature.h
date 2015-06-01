#pragma once

#include "objects\IObject.h"
#include "creatureTypes.h"
#include "items\item.h"
#include "items\ItemContainer.h"
#include "equipmentSlot.h"

namespace creatures
{
   class ICreature : public objects::IObject
   {
   public:
      typedef std::shared_ptr< ICreature > Ptr;

      virtual objects::TObjectType getObjectType() const override final;
      virtual TCreatureType getCreatureType() const = 0;

      void move( gamemap::coord dx, gamemap::coord dy );

      void equip( items::IItem::Ptr );
      items::TItemList getEquipedItems();

      void carryItem( items::IItem::Ptr );
      items::TItemList getStorageItems();

   protected:
      void addSlot( CEquipmentSlot::Ptr );
      void setStorageSlot( CEquipmentSlot::Ptr );

   private:
      items::CItemContainer::Ptr getStorage();

   private:
      TEquipmentSlots slots;
      CEquipmentSlot::WeakPtr storageSlot;
   };
}
