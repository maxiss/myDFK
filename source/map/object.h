#pragma once

#include "point.h"
#include <map>

namespace gamemap
{
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
      coord getx() const { return point.x; }
      coord gety() const { return point.y; }

   private:
      friend CMap;
      TPoint point;
   };

}