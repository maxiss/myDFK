#pragma once

namespace gamemap
{
   typedef int coord;

   struct TPoint
   {
      coord x;
      coord y;
   };

   class TPointComparer
   {
   public:
      bool operator() (const TPoint& left, const TPoint& right ) const
      {
         bool retVal;
         if (left.y == right.y)
            retVal = (left.x < right.x);
         else
            retVal =  (left.y < right.y);
         return retVal;
      }

   };

}
