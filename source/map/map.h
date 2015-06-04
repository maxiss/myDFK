#pragma once

#include <set>
#include "IMap.h"

namespace game_engine
{
   typedef std::set< TCoords > TCoordsSet;

   class CMapPosition;

   class CMap
      : public std::enable_shared_from_this< CMap >
      , public IMap
   {
   public:
      typedef std::shared_ptr< CMap > Ptr;
      typedef std::shared_ptr< const CMap > ConstPtr;
      typedef std::weak_ptr< CMap > WeakPtr;

      CMap( const TCoords& min, const TCoords& max );

      IObject::Ptr getObject( const TCoords&, TObjectType );
      TObjectList getObjects( const TCoords&, TObjectType );
      bool canMove( IObject::Ptr, const TCoords& );

      virtual TMapPointList getMapPositionList() const override final;
      virtual TMapPointList getMapChanges() const override final;
      void clearChanges() const;

      void place( IObject::Ptr, const TCoords& );

   private:
      bool checkBorders( const TCoords& ) const;
      bool checkPassable( const TCoords& ) const;
      void addChange( const TCoords& ) const;
      void tmp_initSturctures();

      friend CMapPosition;
      void addObject( IObject::Ptr, const TCoords& );
      void moveObject( IObject::Ptr obj, const TCoords& );
      void removeObject( IObject::Ptr obj );

   private: // data
      const TCoords min, max;
      CMapData content;
      mutable TCoordsSet changes;

   };

}
