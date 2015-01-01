#pragma once

#include "point.h"
#include <map>

namespace gamemap
{
   class CObject;
   typedef std::multimap< TPoint, CObject* > TMap;
   typedef TMap::iterator TMapIterator;
   class CMap;

   enum TObjectType
   {
      OBJ_TYPE_EMPTY = 1
    , OBJ_TYPE_FLOOR
    , OBJ_TYPE_WALL
    , OBJ_TYPE_CREATURE
    , OBJ_TYPE_ITEM
    , OBJ_TYPE_BUILDING
   };

   class CObject
   {
   public:
      virtual TObjectType getObjectType() const = 0;
      coord getx() const { return mapIterator->first.x; }
      coord gety() const { return mapIterator->first.y; }

   private:
      friend CMap;
      TMap::iterator mapIterator;
   };

}