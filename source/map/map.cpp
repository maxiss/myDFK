#include "map.h"
#include "mapPosition.h"

using namespace game_engine;

CMap::CMap( const TCoords& min_, const TCoords& max_ )
   : min( min_ ), max( max_ )
   , content( min, max )
{
   tmp_initSturctures();
}

void CMap::tmp_initSturctures()
{
   for (coord y = min.y; y <= max.y; y++)
   {
      for (coord x = min.x; x <= max.x; x++)
      {
         content.getStructure( TCoords{ x, y } ).type = TStructureType::floor;

         if ( ( x == max.x - 2 ) && ( y > min.y + 1 ) && ( y < max.y - 1 ) )
            content.getStructure( TCoords{ x, y } ).type = TStructureType::wall;
      }
   }
}

bool CMap::checkBorders( const TCoords& coords ) const
{
   return ( (min.x <= coords.x) && (coords.x <= max.x) && (min.y <= coords.y) && (coords.y <= max.y) );
}

bool CMap::checkPassable( const TCoords& coords ) const
{
   const TStructure& structure = content.getStructure( coords );

   switch ( structure.type )
   {
      case TStructureType::wall :
      case TStructureType::none :
         return false;
      break;

      default :
         return true;
      break;
   }
}

void CMap::addObject( IObject::Ptr obj, const TCoords& coords )
{
   if ( !canMove( obj, coords ) )
      throw std::exception( "can't move object there" );

   content.addObject( obj, coords );

   addChange( coords );
}

void CMap::moveObject( IObject::Ptr obj, const TCoords& coords )
{
   if ( !canMove( obj, coords ) )
      throw std::exception( "can't move object there" );

   const TCoords& oldCoords = content.getObjectCoords( obj );
   addChange( oldCoords );

   content.updateObject( obj, coords );

   addChange( coords );
}

void CMap::removeObject( IObject::Ptr obj )
{
   const TCoords& oldCoords = content.getObjectCoords( obj );
   addChange( oldCoords );

   content.removeObject( obj );
}

TMapPointList CMap::getMapPositionList() const
{
   TMapPointList retVal;

   for (coord y = min.y; y <= max.y; y++)
   {
      for (coord x = min.x; x <= max.x; x++)
      {
         TCoords coords{ x, y };
         retVal.push_back( TMapPoint{ coords, content.getStructure( coords ).type,
                                      content.getConstObjectList( coords, TObjectType::all ) } );
      }
   }

   return retVal;
}

TMapPointList CMap::getMapChanges() const
{
   TMapPointList retVal;

   for ( auto it : changes )
      retVal.push_back( TMapPoint{ it, content.getStructure( it ).type,
                                   content.getConstObjectList( it, TObjectType::all ) } );


   clearChanges();
   return retVal;
}

IObject::Ptr CMap::getObject( const TCoords& coords, TObjectType objectType )
{
   IObject::Ptr retVal;

   TObjectList objectList = content.getObjectList( coords, objectType, 1 );
   if ( !objectList.empty() )
      retVal = *objectList.begin();

   return retVal;
}

TObjectList CMap::getObjects( const TCoords& coords, TObjectType objectType )
{
   return content.getObjectList( coords, objectType );
}

void CMap::addChange( const TCoords& point ) const
{
   changes.insert( point );
}

void CMap::clearChanges() const
{
   changes.clear();
}

bool CMap::canMove( IObject::Ptr, const TCoords& coords )
{
   return checkBorders( coords ) && checkPassable( coords );
}

void CMap::place( IObject::Ptr object, const TCoords& coords )
{
   object->setPosition( std::make_shared< CMapPosition >( object, shared_from_this(), coords ) );
}
