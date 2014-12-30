#include "map.h"

using namespace gamemap;

CMap::CMap( const coord& minX_, const coord& minY_, const coord& maxX_, const coord& maxY_ )
   : minX(minX_), minY(minY_), maxX(maxX_), maxY(maxY_)
{
}

bool CMap::checkBorders( TPoint point ) const
{
   bool retVal = true;
   retVal = (minX <= point.x) && (point.x <= maxX);
   retVal = retVal && (minY <= point.y) && (point.y <= maxY);
   return retVal;
}

void CMap::addObject( gamemap::CObject* obj, const gamemap::TPoint& pos )
{
   if ( checkBorders( pos ) )
   {
      obj->mapIterator = content.insert( std::make_pair( pos, obj ) );
   }
}

void CMap::moveObject( gamemap::CObject* obj, const gamemap::TPoint& pos )
{
   if ( checkBorders( pos ) && ( obj->mapIterator != content.end() ) )
   {
      content.erase( obj->mapIterator );
      addObject( obj, pos );
   }
}

TPositionList CMap::getMapPositionList() const
{
   TPositionList retVal;

   TPoint point;
   TPosition position;
   for (coord y = minY; y <= maxY; y++)
   {
      for (coord x = minX; x <= maxX; x++)
      {
         point.x = x; point.y = y;
         position.position = point;
         TMap::const_iterator pos = content.find( point );
         if ( pos == content.end() )
         {
            position.objectType = OBJ_TYPE_EMPTY;
         }
         else
         {
            position.objectType = pos->second->getObjectType();
         }
         retVal.push_back( position );
      }
   }

   return retVal;
}
