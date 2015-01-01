#pragma once

#include <list>
#include "object.h"

namespace gamemap
{
   typedef std::list< CObject* > TObjectContainer;

   class CBaseObjectContainer
   {
   protected:
      void addObject( CObject* object );
      void removeObject( CObject* object );

   private:
      TObjectContainer content;

   };

}
