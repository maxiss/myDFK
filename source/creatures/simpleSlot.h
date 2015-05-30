#pragma once

#include "equipmentSlot.h"
#include "items\ItemTypes.h"

namespace creatures
{
   class CSimpleSlot
      : public CEquipmentSlot
   {
   public:
      CSimpleSlot( items::TItemType );
      virtual bool canEquip( items::IItem::Ptr ) const override final;

   private:
      items::TItemType itemType;
   };

}
