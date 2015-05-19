#pragma once

#include <map>
#include "item.h"

namespace items
{
   class CContainerPosition;

   class CItemContainer
   {
   public:
      typedef std::shared_ptr< CItemContainer > Ptr;
      typedef std::weak_ptr< CItemContainer > WeakPtr;

      bool isEmpty() const;
      IItem::Ptr get();

   private:
      friend CContainerPosition;
      void add( IItem::Ptr );
      void remove( IItem::Ptr );

   private:
      std::map< IItem::RawPtr, IItem::Ptr > content;
   };
}
