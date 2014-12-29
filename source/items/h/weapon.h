#pragma once

#include "item.h"

namespace items
{
   class CWeapon : public CItem
   {
   public:
      virtual TItemType getItemType();

   };

}
