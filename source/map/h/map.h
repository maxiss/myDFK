#pragma once

#include <list>
#include <set>
#include "mapData.h"

namespace gamemap
{
   typedef std::set< TPoint > TPointSet;

   struct TMapPoint
   {
      TPoint point;
      const CMapPoint& mapPoint;

      TMapPoint( const TPoint& point_, const CMapPoint& mapPoint_ )
         : point( point_) , mapPoint( mapPoint_ ) {}
   };
   typedef std::list< TMapPoint > TMapPointList;

   class CMap
   {
   public:
      CMap( const coord& minX_, const coord& minY_, const coord& maxX_, const coord& maxY_ );

      void addObject( CObject* obj, const TPoint& pos );
      void moveObject( CObject* obj, const TPoint& pos );
      void removeObject( CObject* obj );
      CObject* getObject( const TObjectType& objType,  const TPoint& pos );

      TMapPointList getMapPositionList() const;
      TMapPointList getMapChanges() const;
      void clearChanges() const;

   private:
      const coord minX, minY, maxX, maxY;
      CMapData content;
      mutable TPointSet changes;

      bool checkBorders( const TPoint& point ) const;
      bool checkPassable( const TPoint& point ) const;
      void addChange( const TPoint& point ) const;

   };

}
