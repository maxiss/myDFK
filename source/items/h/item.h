#pragma once

#include "map\h\object.h"
#include "ItemType.h"

namespace items
{
   class CItem : public gamemap::CObject
   {
   public:
      virtual gamemap::TObjectType getObjectType() const;
      virtual TItemType getItemType() = 0;

   private:
      int itemId;

   };

}