#pragma once

#include "map\h\object.h"
#include "ItemType.h"

namespace items
{
   using namespace gamemap;

   class CItem : public CObject
   {
   public:
      virtual TObjectType getObjectType() const;
      virtual TItemType getItemType() = 0;

   };

}