#pragma once

#include <map>
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

      ICreature();

      virtual objects::TObjectType getObjectType() const override final;
      virtual TCreatureType getCreatureType() const = 0;

      items::IItem::Ptr getItem();
      void carryItem( items::IItem::Ptr );

   private:
      items::IItem::Ptr storage;

   };

}
