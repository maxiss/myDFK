#pragma once

#include "objects\IObject.h"
#include "creatureTypes.h"
//#include "map\itemContainer.h"

namespace creatures
{
   using namespace objects;

   class ICreature : public IObject
   {
   public:
      virtual TObjectType getObjectType() const override final;
      virtual TCreatureType getCreatureType() const = 0;

      //CItem* getItem();
      //void carryItem( CItem* item );
      //void dropItem( CItem* item );

   //private:
   //   CItemContainer items;

   };

}
