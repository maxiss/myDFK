#pragma once

#include "point.h"
#include <map>

namespace gamemap
{
   class CMap;

   enum class TObjectType
   {
      empty,
      floor,
      wall,
      creature,
      item,
      building,
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