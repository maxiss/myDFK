#pragma once

#include "baseObjectContainer.h"
#include "items\h\item.h"

namespace gamemap
{
   using namespace items;

   class CItemContainer : public CBaseObjectContainer
   {
   public:
      CItem* get();
      void add( CItem* item );
      void remove( CItem* item );

   };

}
