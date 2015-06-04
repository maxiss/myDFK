#include "mapPosition.h"

using namespace game_engine;

TPositionType CMapPosition::getPositionType() const
{
   return TPositionType::map;
}

CMapPosition::CMapPosition( IObject::Ptr object_, CMap::Ptr map_, const TCoords& coords_ )
   : object{ object_ }
   , map( map_ )
{
   if ( map_->canMove( object_, coords_ ) )
   {
      coords = coords_;
      map_->addObject( object_, coords );
   }
   else
      throw std::exception( "can't add object to map" );
}

IObject::Ptr CMapPosition::getObject()
{
   return object.lock();
}

CMap::Ptr CMapPosition::getMap()
{
   return map.lock();
}

const TCoords& CMapPosition::getCoords() const
{
   return coords;
}

void CMapPosition::setCoords( const TCoords& coords_ )
{
   CMap::Ptr map_ = getMap();
   IObject::Ptr object_ = getObject();
   if ( map_->canMove( object_, coords_ ) )
   {
      coords = coords_;
      map_->moveObject( object_, coords );
   }
}

CMapPosition::~CMapPosition()
{
   CMap::Ptr map_ = getMap();
   if ( !object.expired() )
      map_->removeObject( getObject() );
}
