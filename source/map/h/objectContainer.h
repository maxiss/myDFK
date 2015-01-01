#pragma once

#include "baseObjectContainer.h"

namespace gamemap
{
   class CObjectContainer : public CBaseObjectContainer
   {
   public:
      void add( CObject* object );
      void remove( CObject* object );

   };

}
