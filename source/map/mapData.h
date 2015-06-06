#pragma once

#include <set>
#include <map>
#include "Coords.h"
#include "structure.h"
#include "objects\IObject.h"
#include "CoordsVector.h"

namespace game_engine
{
   class CMapData
   {
   public:
      CMapData( const Coords& min, const Coords& max );

      void addObject( IObject::Ptr, const Coords& );
      void removeObject( IObject::Ptr );
      void updateObject( IObject::Ptr object, const Coords& coords );
      const Coords& getObjectCoords( IObject::Ptr ) const;

      ObjectList getObjectList( const Coords&, ObjectType, size_t = 0 );
      ConstObjectList getConstObjectList( const Coords&, ObjectType, size_t = 0 ) const;

      TStructure& getStructure( const Coords& );
      const TStructure& getStructure( const Coords& ) const;

   private: // data
      const Coords min, max;

      std::map< IObject::RawPtr, IObject::Ptr > content;
      std::map< IObject::RawPtr, Coords > objectCoordIndex;
      CCoordsVector< TStructure > structures;
      CCoordsVector< std::set< IObject::RawPtr > > coordIndex;
   };
}
