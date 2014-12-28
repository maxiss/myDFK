#pragma once

namespace gamemap
{
   typedef int coord;

   struct TPoint
   {
      coord x;
      coord y;

      TPoint() : x(0), y(0) {}
      TPoint( const coord& x_, const coord& y_ ) : x(x_) , y(y_) {}
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
