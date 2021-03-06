#pragma once

#include <map>
#include "item.h"

namespace game_engine
{
   class CContainerPosition;

   class CItemContainer
      : private std::enable_shared_from_this< CItemContainer >
   {
   public:
      typedef std::shared_ptr< CItemContainer > Ptr;
      typedef std::weak_ptr< CItemContainer > WeakPtr;

      ItemList getItems();
      void store( IItem::Ptr );
      bool isEmpty() const;

   private:
      friend CContainerPosition;
      void add( IItem::Ptr );
      void remove( IItem::Ptr );

   private:
      std::map< IItem::RawPtr, IItem::Ptr > content;
   };
}
