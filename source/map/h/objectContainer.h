#pragma once

#include <list>
#include "object.h"

namespace gamemap
{
   class CObjectContainer
   {
   public:
      bool isEmpty() const;
      CObject* get();
      CObject* get() const;
      CObject* get( const TObjectType& objType );
      void add( CObject* object );
      void remove( CObject* object );

   private:
      typedef std::list< CObject* > TObjectList;
      TObjectList content;

   };

}
