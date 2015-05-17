#pragma once

#include "objects\IPositionBehavior.h"
#include "item.h"
#include "ItemContainer.h"
#include "objects\PositionTypes.h"

namespace items
{
   class CContainerPosition : public objects::IPositionBehavior
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
