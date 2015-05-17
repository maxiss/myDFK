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

   class CMapPosition;

   class CMap
   {
   public:
      typedef std::shared_ptr< CMap > Ptr;
      typedef std::shared_ptr< const CMap > ConstPtr;
      typedef std::weak_ptr< CMap > WeakPtr;

      CMap( const TCoords& min, const TCoords& max );

      objects::IObject::Ptr getObject( const TCoords& pos, objects::TObjectType objType );
      bool canMove( objects::IObject::Ptr, const TCoords& );

      TMapPointList getMapPositionList() const;
      TMapPointList getMapChanges() const;
      void clearChanges() const;

   private:
      bool checkBorders( const TCoords& ) const;
      bool checkPassable( const TCoords& ) const;
      void addChange( const TCoords& ) const;
      void tmp_initSturctures();

      friend CMapPosition;
      void addObject( objects::IObject::Ptr, const TCoords& );
      void moveObject( objects::IObject::Ptr obj, const TCoords& );
      void removeObject( objects::IObject::Ptr obj );

   private: // data
      const TCoords min, max;
      CMapData content;
      mutable TCoordsSet changes;

   };

}
