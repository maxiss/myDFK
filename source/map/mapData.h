#pragma once

#include <set>
#include <map>
#include "TCoords.h"
#include "structure.h"
#include "objects\IObject.h"
#include "CoordsVector.h"

namespace game_engine
{
   class CMapData
   {
   public:
      CMapData( const TCoords& min, const TCoords& max );

      void addObject( IObject::Ptr, const TCoords& );
      void removeObject( IObject::Ptr );
      void updateObject( IObject::Ptr object, const TCoords& coords );
      const TCoords& getObjectCoords( IObject::Ptr ) const;

      TObjectList getObjectList( const TCoords&, TObjectType, size_t = 0 );
      TConstObjectList getConstObjectList( const TCoords&, TObjectType, size_t = 0 ) const;

      TStructure& getStructure( const TCoords& );
      const TStructure& getStructure( const TCoords& ) const;

   private: // data
      const TCoords min, max;

      std::map< IObject::RawPtr, IObject::Ptr > content;
      std::map< IObject::RawPtr, TCoords > objectCoordIndex;
      CCoordsVector< TStructure > structures;
      CCoordsVector< std::set< IObject::RawPtr > > coordIndex;
   };
}
