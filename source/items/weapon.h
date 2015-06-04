#pragma once

#include "item.h"

namespace game_engine
{
   class CWeapon : public IItem
   {
   public:
      virtual TItemType getItemType() const override final;
      virtual std::string getName() const override;
   };
}
