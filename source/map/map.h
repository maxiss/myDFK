#pragma once

#include <set>
#include "IMap.h"

namespace game_engine
{
   typedef std::set< Coords > TCoordsSet;

   class CMapPosition;

   class CMap
      : public std::enable_shared_from_this< CMap >
      , public IMap
   {
   public:
      typedef std::shared_ptr< CMap > Ptr;
      typedef std::shared_ptr< const CMap > ConstPtr;
      typedef std::weak_ptr< CMap > WeakPtr;

      CMap( const Coords& min, const Coords& max );

      ObjectList getObjects( const Coords&, ObjectType );
      void place( IObject::Ptr, const Coords& );

      bool canMove( IObject::Ptr, const Coords& );

      virtual MapPointList getMapPositionList() const override final;
      virtual MapPointList getMapChanges() const override final;
      void clearChanges() const;


   private:
      bool checkBorders( const Coords& ) const;
      bool checkPassable( const Coords& ) const;
      void addChange( const Coords& ) const;
      void tmp_initSturctures();

      friend CMapPosition;
      void addObject( IObject::Ptr, const Coords& );
      void moveObject( IObject::Ptr obj, const Coords& );
      void removeObject( IObject::Ptr obj );

   private: // data
      const Coords min, max;
      CMapData content;
      mutable TCoordsSet changedCoords;

   };

}
