#pragma once

#include <list>
#include <set>
#include "mapData.h"

namespace gamemap
{
   typedef std::set< TCoords > TCoordsSet;

   struct TMapPoint
   {
      TCoords coords;
      TStructureType structureType;
      objects::TConstObjectList objectList;
   };

   typedef std::list< TMapPoint > TMapPointList;

   class CMap
   {
   public:
      CMap( const TCoords& min, const TCoords& max );

      void addObject( objects::IObject::Ptr, const TCoords& );
      void moveObject( objects::IObject::Ptr obj, const TCoords& );
      void removeObject( objects::IObject::Ptr obj );
      objects::IObject::Ptr getObject( const TCoords& pos, objects::TObjectType objType );

      TMapPointList getMapPositionList() const;
      TMapPointList getMapChanges() const;
      void clearChanges() const;

   private:
      const TCoords min, max;
      CMapData content;
      mutable TCoordsSet changes;

      bool checkBorders( const TCoords& ) const;
      bool checkPassable( const TCoords& ) const;
      void addChange( const TCoords& ) const;

      void tmp_initSturctures();
   };

}
