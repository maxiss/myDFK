#pragma once

#include "item.h"
#include "ItemContainer.h"

namespace items
{
   class CBackPack : public IItem
   {
   public:
      CBackPack();

      virtual TItemType getItemType() const override final;

      IItem::Ptr get();
      void store( IItem::Ptr );
      bool isEmpty() const;

   private:
      CItemContainer::Ptr content;

   };


}
