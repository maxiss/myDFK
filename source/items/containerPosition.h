#pragma once

#include "objects\IPosition.h"
#include "item.h"
#include "ItemContainer.h"

namespace game_engine
{
   class CContainerPosition : public IPosition
   {
   public: 
      CContainerPosition( IItem::Ptr, CItemContainer::Ptr );
      ~CContainerPosition();

      virtual TPositionType getPositionType() const override final;
      CItemContainer::Ptr getContainer();

   private:
      IItem::Ptr getItem();

   private: // data
      IItem::WeakPtr item;
      CItemContainer::WeakPtr container;
   };
}
