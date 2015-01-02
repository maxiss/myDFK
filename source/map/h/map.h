#pragma once

#include <map>
#include <list>
#include <set>
#include "point.h"
#include "object.h"
#include "objectContainer.h"

namespace gamemap
{
   class CMapPoint : public CObjectContainer
   {
   };

   typedef std::map< TPoint, CMapPoint > TMap;
   typedef TMap::iterator TMapIterator;
   typedef std::set< TPoint > TPointSet;

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
      TPositionList getMapChanges() const;
      void clearChanges() const;

   private:
      const coord minX, minY, maxX, maxY;
      TMap content;
      mutable TPointSet changes;
      bool checkBorders( TPoint point ) const;
      void addChange( const TPoint& point ) const;

   };

}
