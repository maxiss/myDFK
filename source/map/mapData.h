#pragma once

#include <vector>
#include "objectContainer.h"
#include "structure.h"

namespace gamemap
{
   class CMapPoint : public CObjectContainer
   {
   public:
      TStructure structure;
   };

   class CMapData
   {
   public:
      CMapData( const coord& minX_, const coord& minY_, const coord& maxX_, const coord& maxY_ );

      CMapPoint& operator () ( const TPoint& point );
      const CMapPoint& operator () ( const TPoint& point ) const;

      CMapPoint& operator () ( const coord& x, const coord& y );
      const CMapPoint& operator () ( const coord& x, const coord& y ) const;

   private:
      const coord minX, minY, maxX, maxY;
      std::vector< CMapPoint > content;

      long convert( const coord& x, const coord& y ) const;

   };

}

