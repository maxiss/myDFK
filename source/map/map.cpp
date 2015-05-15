#include "map.h"

using namespace gamemap;
using namespace objects;

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
   if ( checkBorders( coords ) && checkPassable( coords ) )
   {
      obj->setCoords( coords );
      content.addObject( obj );
      addChange( coords );
   }
}

void CMap::moveObject( IObject::Ptr obj, const TCoords& coords )
{
   if ( checkBorders( coords ) && checkPassable( coords ) )
   {
      addChange( obj->getCoords() );

      obj->setCoords( coords );
      content.updateObject( obj );

      addChange( coords );
   }
}

void CMap::removeObject( IObject::Ptr obj )
{
   addChange( obj->getCoords() );

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

   return retVal;
}

IObject::Ptr CMap::getObject( const TCoords& coords, TObjectType objectType )
{
   IObject::Ptr retVal;

   TObjectList objectList = content.getObjectList( coords, objectType );
   if ( !objectList.empty() )
      retVal = *objectList.begin();

   return retVal;
}

void CMap::addChange( const TCoords& point ) const
{
   changes.insert( point );
}

void CMap::clearChanges() const
{
   changes.clear();
}
