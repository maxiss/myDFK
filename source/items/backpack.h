#pragma once

#include "item.h"
#include "ItemContainer.h"

namespace game_engine
{
   class CBackPack final
      : public IItem
      , public CItemContainer
   {
   public:
      virtual ItemType getItemType() const override final;
      virtual std::string getName() const override;
   };
}
