#include "map.h"

using namespace gamemap;

CMap::CMap( const coord& minX_, const coord& minY_, const coord& maxX_, const coord& maxY_ )
   : minX(minX_), minY(minY_), maxX(maxX_), maxY(maxY_)
   , content( minX_, minY_, maxX_, maxY_ )
{
   for (coord y = minY; y <= maxY; y++)
   {
      for (coord x = minX; x <= maxX; x++)
      {
         content( x, y ).structure.type = TStructureType::floor;
         if ( ( x == maxX - 2 ) && ( y > minY + 1 ) && ( y < maxY - 1 ) )
            content( x, y ).structure.type = TStructureType::wall;
      }
   }
}

bool CMap::checkBorders( const TPoint& point ) const
{
   return ( (minX <= point.x) && (point.x <= maxX) && (minY <= point.y) && (point.y <= maxY) );
}

bool CMap::checkPassable( const TPoint& point ) const
{
   if ( content( point ).structure.type == TStructureType::wall )
      return false;
   if ( content( point ).structure.type == TStructureType::none )
      return false;

   return true;
}

void CMap::addObject( CObject* obj, const TPoint& pos )
{
   if ( checkBorders( pos ) && checkPassable( pos ) )
   {
      content( pos ).add( obj );
      obj->point = pos;

      addChange( pos );
   }
}

void CMap::moveObject( CObject* obj, const TPoint& pos )
{
   if ( checkBorders( pos ) && checkPassable( pos ) )
   {
      addChange( obj->point );

      content( obj->point ).remove( obj );
      content( pos ).add( obj );
      obj->point = pos;

      addChange( pos );
   }
}

void CMap::removeObject( CObject* obj )
{
   addChange( obj->point );

   content( obj->point ).remove( obj );
}

TMapPointList CMap::getMapPositionList() const
{
   TMapPointList retVal;

   for (coord y = minY; y <= maxY; y++)
   {
      for (coord x = minX; x <= maxX; x++)
      {
         retVal.push_back( TMapPoint( TPoint( x, y ), content( x, y ) ) );
      }
   }

   return retVal;
}

TMapPointList CMap::getMapChanges() const
{
   TMapPointList retVal;

   TPointSet::const_iterator it = changes.begin();
   while ( it != changes.end() )
   {
      retVal.push_back( TMapPoint( *it, content( *it ) ) );

      ++it;
   }

   return retVal;
}

CObject* CMap::getObject( const TObjectType& objType,  const TPoint& pos )
{
   CObject* retVal = nullptr;

   CMapPoint& mapPoint = content( pos );

   if ( !mapPoint.isEmpty() )
   {
      retVal = mapPoint.get( objType );
   }

   return retVal;
}

void CMap::addChange( const TPoint& point ) const
{
   changes.insert( point );
}

void CMap::clearChanges() const
{
   changes.clear();
}
