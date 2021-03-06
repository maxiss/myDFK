#pragma once

#include "objects\IObject.h"
#include "ItemTypes.h"
#include <list>

namespace game_engine
{
   class IItem : public IObject
   {
   public:
      typedef std::shared_ptr< IItem > Ptr;
      typedef std::weak_ptr< IItem > WeakPtr;
      typedef const IItem* RawPtr;

      virtual ObjectType getObjectType() const override final;
      virtual ItemType getItemType() const = 0;
   };

   typedef std::list< IItem::Ptr > ItemList;
}
