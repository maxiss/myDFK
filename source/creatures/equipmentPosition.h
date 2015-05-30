#pragma once

#include "objects/IPosition.h"
#include "equipmentSlot.h"

namespace creatures
{
   class CEquipmentPosition
      : public objects::IPosition
   {
   public:
      CEquipmentPosition( items::IItem::Ptr, CEquipmentSlot::Ptr );
      ~CEquipmentPosition();

      virtual objects::TPositionType getPositionType() const override final;
      CEquipmentSlot::Ptr getEquipmentSlot();

   private:
      items::IItem::Ptr getItem();

   private:
      items::IItem::WeakPtr item;
      CEquipmentSlot::WeakPtr slot;
   };
}
