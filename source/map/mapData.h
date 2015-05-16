#pragma once

#include <set>
#include <vector>
#include <map>
#include "TCoords.h"
#include "structure.h"
#include "objects\IObject.h"
#include "CoordsVector.h"

namespace gamemap
{
   class CMapData
   {
   public:
      CMapData( const TCoords& min, const TCoords& max );

      void addObject( objects::IObject::Ptr, const TCoords& );
      void removeObject( objects::IObject::Ptr );
      void updateObject( objects::IObject::Ptr object, const TCoords& coords );
      const TCoords& getObjectCoords( objects::IObject::Ptr ) const;

      objects::TObjectList getObjectList( const TCoords&, objects::TObjectType, size_t = 1 );
      objects::TConstObjectList getConstObjectList( const TCoords&, objects::TObjectType, size_t = 1 ) const;

      TStructure& getStructure( const TCoords& );
      const TStructure& getStructure( const TCoords& ) const;

   private: // data
      const TCoords min, max;

      std::map< objects::IObject::RawPtr, objects::IObject::Ptr > content;
      std::map< objects::IObject::RawPtr, TCoords > objectCoordIndex;
      CCoordsVector< TStructure > structures;
      CCoordsVector< std::set< objects::IObject::RawPtr > > coordIndex;
   };
}
