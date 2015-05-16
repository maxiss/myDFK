#include "mapPosition.h"
#include "mapInstance.h"

using namespace gamemap;
using namespace objects;

TPositionType CMapPosition::getPositionType() const
{
   return TPositionType::map;
}

CMapPosition::CMapPosition( IObject::Ptr object_, const TCoords& coords_ )
   : object{ object_ }
{
   CMap& map = getMap();
   if ( map.canMove( object.lock(), coords_ ) )
   {
      coords = coords_;
      map.addObject( object.lock(), coords );
   }
   else
      throw std::exception( "can't add object to map" );
}

CMap& CMapPosition::getMap() const
{
   return Map::Intance().getMap();
}

const TCoords& CMapPosition::getCoords() const
{
   return coords;
}

void CMapPosition::setCoords( const TCoords& coords_ )
{
   CMap& map = getMap();
   if ( map.canMove( object.lock(), coords_ ) )
   {
      coords = coords_;
      map.moveObject( object.lock(), coords );
   }
}
