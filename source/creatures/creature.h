#pragma once

#include <map>
#include "objects\IObject.h"
#include "creatureTypes.h"
#include "items\item.h"

namespace creatures
{
   using namespace objects;

   class ICreature : public IObject
   {
   public:
      typedef std::shared_ptr< ICreature > Ptr;
      virtual TObjectType getObjectType() const override final;
      virtual TCreatureType getCreatureType() const = 0;

      items::IItem::Ptr getItem();
      void carryItem( items::IItem::Ptr );
      void dropItem( items::IItem::Ptr );

   private:
      std::map < items::IItem::RawPtr, items::IItem::Ptr > itemContainer;

   };

}
