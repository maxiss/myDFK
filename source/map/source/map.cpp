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

void CMap::addObject( CObject* obj, const TPoint& pos )
{
   if ( checkBorders( pos ) )
   {
      content[ pos ].add( obj );
      obj->point = pos;

      addChange( pos );
   }
}

void CMap::moveObject( CObject* obj, const TPoint& pos )
{
   if ( checkBorders( pos ) )
   {
      addChange( obj->point );

      content[ obj->point ].remove( obj );
      content[ pos ].add( obj );
      obj->point = pos;

      addChange( pos );
   }
}

void CMap::removeObject( CObject* obj )
{
   addChange( obj->point );

   content[ obj->point ].remove( obj );
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
            position.objectType = pos->second.get()->getObjectType();
         }
         retVal.push_back( position );
      }
   }

   return retVal;
}

TPositionList CMap::getMapChanges() const
{
   TPositionList retVal;

   TPosition position;
   TMap::const_iterator mapIt;

   TPointSet::const_iterator it = changes.begin();
   while ( it != changes.end() )
   {
      position.position = *it;

      mapIt = content.find( position.position );
      if ( ( mapIt == content.end() ) || ( mapIt->second.isEmpty() ) )
      {
         position.objectType = OBJ_TYPE_EMPTY;
      }
      else
      {
         position.objectType = mapIt->second.get()->getObjectType();
      }
      retVal.push_back( position );

      ++it;
   }
   return retVal;
}

CObject* CMap::getObject( const TObjectType& objType,  const TPoint& pos )
{
   CObject* retVal = nullptr;

   TMap::iterator it = content.find( pos );
   if ( it != content.end() )
   {
      retVal = it->second.get( objType );
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
