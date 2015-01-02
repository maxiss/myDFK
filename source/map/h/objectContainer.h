#pragma once

#include "baseObjectContainer.h"

namespace gamemap
{
   class CObjectContainer : protected CBaseObjectContainer
   {
   public:
      bool isEmpty() const;
      CObject* get();
      CObject* get() const;
      CObject* get( const TObjectType& objType );
      void add( CObject* object );
      void remove( CObject* object );

   };

}
