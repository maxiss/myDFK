#pragma once

#include "map\object.h"
#include "creatureTypes.h"
#include "map\itemContainer.h"

namespace creatures
{
   using namespace gamemap;

   class CCreature : public CObject
   {
   public:
      virtual TObjectType getObjectType() const;
      virtual TCreatureType getCreatureType() = 0;

      CItem* getItem();
      void carryItem( CItem* item );
      void dropItem( CItem* item );

   private:
      CItemContainer items;

   };

}
