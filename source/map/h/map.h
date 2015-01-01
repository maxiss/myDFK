#pragma once

#include <map>
#include <list>
#include "point.h"
#include "object.h"

namespace gamemap
{
   typedef std::multimap< TPoint, CObject* > TMap;
   typedef TMap::iterator TMapIterator;

   struct TPosition // will remove
   {
      TPoint position;
      TObjectType objectType;
   };
   typedef std::list< TPosition > TPositionList;

   class CMap
   {
   public:
      CMap( const coord& minX_, const coord& minY_, const coord& maxX_, const coord& maxY_ );

      void addObject( CObject* obj, const TPoint& pos );
      void moveObject( CObject* obj, const TPoint& pos );
      void removeObject( CObject* obj );
      CObject* getObject( const TObjectType& objType,  const TPoint& pos );

      TPositionList getMapPositionList() const;

   private:
      const coord minX, minY, maxX, maxY;
      TMap content;
      bool checkBorders( TPoint point ) const;

   };

}
