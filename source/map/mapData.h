#pragma once

#include <set>
#include <vector>
#include <map>
#include "point.h"
#include "structure.h"
#include "objects\IObject.h"

namespace gamemap
{
   class CMapData
   {
   public:
      CMapData( const TCoords& min, const TCoords& max );

      void addObject( objects::IObject::Ptr );
      void removeObject( objects::IObject::Ptr );
      void updateObject( objects::IObject::Ptr );
      objects::TObjectList getObjectList( const TCoords&, objects::TObjectType, size_t = 1 );
      objects::TConstObjectList getConstObjectList( const TCoords&, objects::TObjectType, size_t = 1 ) const;

      TStructure& operator[] ( const TCoords& );
      const TStructure& operator[] ( const TCoords& ) const;

   private:
      long convert( const TCoords& coords ) const;

   private: // data
      const TCoords min, max;
      const long cellCount;

      std::map< objects::IObject::RawPtr, objects::IObject::Ptr > content;
      std::map< objects::IObject::RawPtr, TCoords > objectCoordIndex;
      std::vector< TStructure > structures;
      std::vector< std::set< objects::IObject::RawPtr > > coordIndex;
   };
}
