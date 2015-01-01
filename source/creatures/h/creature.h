#pragma once

#include "map\h\object.h"
#include "creatureTypes.h"
#include "map\h\itemContainer.h"

namespace creatures
{
   using namespace gamemap;

   class CCreature : public CObject
   {
   public:
      virtual TObjectType getObjectType() const;
      virtual TCreatureType getCreatureType() = 0;

      void carryItem( CItem* item );
      void dropAllItems();

   private:
      CItemContainer items;

   };

}
