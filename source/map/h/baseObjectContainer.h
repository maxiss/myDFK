#pragma once

#include <list>
#include "object.h"

namespace gamemap
{
   typedef std::list< CObject* > TObjectList;

   class CBaseObjectContainer
   {
   protected:
      CObject* getObject();
      void addObject( CObject* object );
      void removeObject( CObject* object );

   private:
      TObjectList content;

   };

}
