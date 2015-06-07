#include "map.h"
#include "mapPosition.h"

using namespace game_engine;

CMap::CMap( const Coords& min_, const Coords& max_ )
   : min( min_ ), max( max_ )
   , content( min, max )
{
   tmp_initSturctures();
}

void CMap::tmp_initSturctures()
{
   for (Coord y = min.y; y <= max.y; y++)
   {
      for (Coord x = min.x; x <= max.x; x++)
      {
         content.getStructure( Coords{ x, y } ).type = StructureType::Floor;

         if ( ( x == max.x - 2 ) && ( y > min.y + 1 ) && ( y < max.y - 1 ) )
            content.getStructure( Coords{ x, y } ).type = StructureType::Wall;
      }
   }
}

bool CMap::checkBorders( const Coords& coords ) const
{
   return ( (min.x <= coords.x) && (coords.x <= max.x) && (min.y <= coords.y) && (coords.y <= max.y) );
}

bool CMap::checkPassable( const Coords& coords ) const
{
   const TStructure& structure = content.getStructure( coords );

   switch ( structure.type )
   {
      case StructureType::Wall :
      case StructureType::None :
         return false;
      break;

      default :
         return true;
      break;
   }
}

void CMap::addObject( IObject::Ptr obj, const Coords& coords )
{
   if ( !canMove( obj, coords ) )
      throw std::exception( "can't move object there" );

   content.addObject( obj, coords );

   addChange( coords );
}

void CMap::moveObject( IObject::Ptr obj, const Coords& coords )
{
   if ( !canMove( obj, coords ) )
      throw std::exception( "can't move object there" );

   const Coords& oldCoords = content.getObjectCoords( obj );
   addChange( oldCoords );

   content.updateObject( obj, coords );

   addChange( coords );
}

void CMap::removeObject( IObject::Ptr obj )
{
   const Coords& oldCoords = content.getObjectCoords( obj );
   addChange( oldCoords );

   content.removeObject( obj );
}

MapPointList CMap::getMapPositionList() const
{
   MapPointList retVal;

   for (Coord y = min.y; y <= max.y; y++)
   {
      for (Coord x = min.x; x <= max.x; x++)
      {
         Coords coords = { x, y };
         retVal.push_back( { coords, content.getStructure( coords ).type,
                             content.getConstObjectList( coords, ObjectType::All ) } );
      }
   }

   return retVal;
}

MapPointList CMap::getMapChanges() const
{
   MapPointList retVal;

   for ( auto coords : changedCoords )
      retVal.push_back( { coords, content.getStructure( coords ).type,
                          content.getConstObjectList( coords, ObjectType::All ) } );

   clearChanges();
   return retVal;
}

ObjectList CMap::getObjects( const Coords& coords, ObjectType objectType )
{
   return content.getObjectList( coords, objectType );
}

void CMap::addChange( const Coords& point ) const
{
   changedCoords.insert( point );
}

void CMap::clearChanges() const
{
   changedCoords.clear();
}

bool CMap::canMove( IObject::Ptr, const Coords& coords )
{
   return checkBorders( coords ) && checkPassable( coords );
}

void CMap::place( IObject::Ptr object, const Coords& coords )
{
   object->setPosition( std::make_shared< CMapPosition >( object, shared_from_this(), coords ) );
}
