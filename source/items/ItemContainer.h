#pragma once

#include "item.h"

namespace items
{
   class CItemContainer
   {
   public:
      void add( IItem::Ptr item );
      void remove( IItem::Ptr item );
      bool isEmpty() const;

      IItem::Ptr get() const;

   private:
      std::list< IItem::Ptr > content;
   };
}
