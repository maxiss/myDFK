#pragma once

#include "ItemType.h"

namespace items
{
   class CItem
   {
   public:
      virtual TItemType getItemType() = 0;

   private:
      int itemId;

   };

}