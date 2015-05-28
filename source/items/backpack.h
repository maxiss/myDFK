#pragma once

#include "item.h"
#include "ItemContainer.h"

namespace items
{
   class CBackPack final
      : public IItem
      , public CItemContainer
   {
   public:
      virtual TItemType getItemType() const override final;
      virtual std::string getName() const override;
   };
}
