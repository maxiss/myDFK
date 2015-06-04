#pragma once

#include "equipmentSlot.h"
#include "items\ItemTypes.h"

namespace game_engine
{
   class CSimpleSlot
      : public CEquipmentSlot
   {
   public:
      CSimpleSlot( TItemType );
      virtual bool canEquip( IItem::Ptr ) const override final;

   private:
      TItemType itemType;
   };

}
