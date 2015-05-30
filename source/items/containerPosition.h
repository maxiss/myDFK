#pragma once

#include "objects\IPosition.h"
#include "item.h"
#include "ItemContainer.h"

namespace items
{
   class CContainerPosition : public objects::IPosition
   {
   public: 
      CContainerPosition( IItem::Ptr, CItemContainer::Ptr );
      ~CContainerPosition();

      virtual objects::TPositionType getPositionType() const override final;
      CItemContainer::Ptr getContainer();

   private:
      IItem::Ptr getItem();

   private: // data
      IItem::WeakPtr item;
      CItemContainer::WeakPtr container;
   };
}
