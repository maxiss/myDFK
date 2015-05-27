#pragma once

#include "objects\IObject.h"
#include "creatureTypes.h"
#include "items\item.h"
#include "items\ItemContainer.h"

namespace creatures
{
   class ICreature : public objects::IObject
   {
   public:
      typedef std::shared_ptr< ICreature > Ptr;

      virtual objects::TObjectType getObjectType() const override final;
      virtual TCreatureType getCreatureType() const = 0;

      items::IItem::Ptr getItem();
      void carryItem( items::IItem::Ptr );
      void move( gamemap::coord dx, gamemap::coord dy );

   protected:
      items::CItemContainer::Ptr storage;

   };

}
