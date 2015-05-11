#pragma once

#include "objectContainer.h"
#include "items\item.h"

namespace gamemap
{
   using namespace items;

   class CItemContainer : protected CObjectContainer
   {
   public:
      CItem* get();
      void add( CItem* item );
      void remove( CItem* item );

   };

}
