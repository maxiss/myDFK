#pragma once

#include "objects/IPosition.h"
#include "equipmentSlot.h"

namespace game_engine
{
   class CEquipmentPosition
      : public IPosition
   {
   public:
      CEquipmentPosition( IItem::Ptr, CEquipmentSlot::Ptr );
      ~CEquipmentPosition();

      virtual TPositionType getPositionType() const override final;
      CEquipmentSlot::Ptr getEquipmentSlot();

   private:
      IItem::Ptr getItem();

   private:
      IItem::WeakPtr item;
      CEquipmentSlot::WeakPtr slot;
   };
}
