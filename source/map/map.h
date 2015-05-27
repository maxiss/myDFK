#pragma once

#include <set>
#include "IMap.h"

namespace gamemap
{
   typedef std::set< TCoords > TCoordsSet;

   class CMapPosition;

   class CMap : public IMap
   {
   public:
      typedef std::shared_ptr< CMap > Ptr;
      typedef std::shared_ptr< const CMap > ConstPtr;
      typedef std::weak_ptr< CMap > WeakPtr;

      CMap( const TCoords& min, const TCoords& max );

      objects::IObject::Ptr getObject( const TCoords&, objects::TObjectType );
      objects::TObjectList getObjects( const TCoords&, objects::TObjectType );
      bool canMove( objects::IObject::Ptr, const TCoords& );

      virtual TMapPointList getMapPositionList() const override final;
      virtual TMapPointList getMapChanges() const override final;
      void clearChanges() const;

      //void place( objects::IObject::Ptr, const TCoods& ); // !!!

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
