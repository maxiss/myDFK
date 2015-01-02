#pragma once

#include <list>
#include "object.h"

namespace gamemap
{
   typedef std::list< CObject* > TObjectList;

   class CBaseObjectContainer
   {
   protected:
      bool isEmpty() const;
      CObject* getObject();
      CObject* getObject() const;
      CObject* getObject( const TObjectType& objType );
      void addObject( CObject* object );
      void removeObject( CObject* object );

   private:
      TObjectList content;

   };

}
