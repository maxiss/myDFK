#pragma once

#include "objects/IPosition.h"
#include "equipmentSlot.h"

namespace items
{
   class CEquipmentPosition
      : public objects::IPosition
   {
   public:
      CEquipmentPosition( IItem::Ptr, CEquipmentSlot::Ptr );
      ~CEquipmentPosition();

      virtual objects::TPositionType getPositionType() const override final;
      CEquipmentSlot::Ptr getEquipmentSlot();

   private:
      IItem::Ptr getItem();

   private:
      IItem::WeakPtr item;
      CEquipmentSlot::WeakPtr slot;
   };
}
