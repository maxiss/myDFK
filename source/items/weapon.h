#pragma once

#include "item.h"

namespace items
{
   class CWeapon : public IItem
   {
   public:
      virtual TItemType getItemType() const override final;
      virtual std::string getName() const override;
   };
}
