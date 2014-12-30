#pragma once

#include <map>
#include <list>
#include "point.h"
#include "object.h"

namespace gamemap
{
   typedef std::multimap< TPoint, CObject*, TPointComparer > TMap;
   typedef TMap::iterator TMapIterator;

   struct TPosition
   {
      TPoint position;
      TObjectType objectType;
   };
   typedef std::list< TPosition > TPositionList;

   class CMap
   {
   public:
      CMap( const coord& minX_, const coord& minY_, const coord& maxX_, const coord& maxY_ );

      void addObject( gamemap::CObject* obj, const gamemap::TPoint& pos );
      void moveObject( gamemap::CObject* obj, const gamemap::TPoint& pos );

      TPositionList getMapPositionList() const;

   private:
      const coord minX, minY, maxX, maxY;
      TMap content;
      bool checkBorders( TPoint point ) const;

   };

}
