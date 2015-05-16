#pragma once

namespace gamemap
{
   typedef unsigned int coord;

   struct TCoords
   {
      coord x;
      coord y;
   };

   inline bool operator < (const TCoords& left, const TCoords& right )
   {
      bool retVal;
      if (left.y == right.y)
         retVal = (left.x < right.x);
      else
         retVal = (left.y < right.y);
      return retVal;
   }

   inline bool operator == ( const TCoords& pos1, const TCoords& pos2 )
   {
      return ( (pos1.x == pos2.x) && (pos1.y == pos2.y) );
   }

}
