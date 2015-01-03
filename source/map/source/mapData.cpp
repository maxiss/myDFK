#include "mapData.h"

using namespace gamemap;

CMapData::CMapData( const coord& minX_, const coord& minY_, const coord& maxX_, const coord& maxY_ )
   : minX(minX_), minY(minY_), maxX(maxX_), maxY(maxY_)
   , content( ( maxX - minX + 1 ) * ( maxY - minY + 1 ) )
{
}

long CMapData::convert( const coord& x, const coord& y ) const
{
   return ( y - minY ) * ( maxX - minX + 1 ) + ( x - minX );
}

CMapPoint& CMapData::operator () ( const coord& x, const coord& y )
{
   return content[ convert( x, y ) ];
}

const CMapPoint& CMapData::operator () ( const coord& x, const coord& y ) const
{
   return content[ convert( x, y ) ];
}

CMapPoint& CMapData::operator () ( const TPoint& point )
{
   return operator()( point.x, point.y );
}

const CMapPoint& CMapData::operator () ( const TPoint& point ) const
{
   return operator()( point.x, point.y );
}
