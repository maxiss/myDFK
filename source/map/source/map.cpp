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
      obj->mapIterator = content.insert( std::make_pair( pos, obj ) );

      addChange( pos );
   }
}

void CMap::moveObject( CObject* obj, const TPoint& pos )
{
   if ( checkBorders( pos ) && ( obj->mapIterator != content.end() ) )
   {
      addChange( obj->mapIterator->first );

      content.erase( obj->mapIterator );
      addObject( obj, pos );

      addChange( pos );
   }
}

void CMap::removeObject( CObject* obj )
{
   if ( obj->mapIterator != content.end() )
   {
      addChange( obj->mapIterator->first );

      content.erase( obj->mapIterator );
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
      if ( mapIt == content.end() )
      {
         position.objectType = OBJ_TYPE_EMPTY;
      }
      else
      {
         position.objectType = mapIt->second->getObjectType();
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
      while ( it->first == pos )
      {
         if ( it->second->getObjectType() == objType )
         {
            retVal = it->second;
            break;
         }

         if ( ++it == content.end() )
            break;
      }
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
