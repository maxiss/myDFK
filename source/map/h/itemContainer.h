#pragma once

#include "baseObjectContainer.h"
#include "items\h\item.h"

namespace gamemap
{
   class CItemContainer : public CBaseObjectContainer
   {
   public:
      void add( items::CItem* item );
      void remove( items::CItem* item );

   };

}
