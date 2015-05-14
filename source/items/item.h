#pragma once

#include "objects\IObject.h"
#include "ItemTypes.h"

namespace items
{
   class IItem : public objects::IObject
   {
   public:
      typedef std::shared_ptr< IItem > Ptr;

      virtual objects::TObjectType getObjectType() const override final;
      virtual TItemType getItemType() const = 0;
   };
}
