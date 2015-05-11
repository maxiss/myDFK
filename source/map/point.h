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

   inline bool operator < (const TPoint& left, const TPoint& right )
   {
      bool retVal;
      if (left.y == right.y)
         retVal = (left.x < right.x);
      else
         retVal =  (left.y < right.y);
      return retVal;
   }

   inline bool operator == ( const TPoint& pos1, const TPoint& pos2 )
   {
      return ( (pos1.x == pos2.x) && (pos1.y == pos2.y) );
   }

}
