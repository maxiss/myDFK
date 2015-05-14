#include "mapData.h"

using namespace gamemap;
using namespace objects;

CMapData::CMapData( const TCoords& min_, const TCoords& max_ )
   : min(min_), max(max_)
   , cellCount( (max.x - min.x + 1) * (max.y - min.y + 1) )
   , structures( cellCount )
   , coordIndex( cellCount )
{
}

void CMapData::addObject( objects::IObject::Ptr obj )
{
   const IObject* objId = obj.get();
   content.insert( make_pair( objId, obj ) );

   const TCoords coords = obj->getCoords();
   objectCoordIndex[ objId ] = coords;
   coordIndex[ convert( coords ) ].insert( objId );
}

void CMapData::removeObject( objects::IObject::Ptr obj )
{
   const IObject* objId = obj.get();
   const TCoords coords = objectCoordIndex[ objId ];

   coordIndex[ convert( coords ) ].erase( objId );
   objectCoordIndex.erase( objId );
   content.erase( objId );
}

void CMapData::updateObject( objects::IObject::Ptr obj )
{
   const IObject* objId = obj.get();
   const TCoords oldCoords = objectCoordIndex[ objId ];
   coordIndex[ convert( oldCoords ) ].erase( objId );

   const TCoords newCoords = obj->getCoords();
   objectCoordIndex[ objId ] = newCoords;
   coordIndex[ convert( newCoords ) ].insert( objId );
}

TObjectList CMapData::getObjectList( const TCoords& coords, TObjectType objectType_, size_t count )
{
   _ASSERT( count > 0 );
   TObjectList retVal;

   auto& objectIdSet = coordIndex[ convert( coords ) ];
   for ( auto it : objectIdSet )
   {
      IObject::Ptr object = content[ it ];
      TObjectType objectType = object->getObjectType();
      if ( objectType == TObjectType::all || objectType == objectType_ )
      {
         retVal.push_back( object );
         if ( retVal.size() == count )
            break;
      }
   }

   return retVal;
}

TConstObjectList CMapData::getConstObjectList( const TCoords& coords, TObjectType objectType_, size_t count ) const
{
   _ASSERT( count > 0 );
   TConstObjectList retVal;

   auto& objectIdSet = coordIndex[ convert( coords ) ];
   for ( auto it: objectIdSet )
   {
      auto object = content.find( it );
      if ( object != content.end() )
      {
         TObjectType objectType = object->second->getObjectType();
         if ( objectType == TObjectType::all || objectType == objectType_ )
         {
            retVal.push_back( object->second );
            if ( retVal.size() == count )
               break;
         }
      }
   }

   return retVal;
}

TStructure& CMapData::operator[] ( const TCoords& coords )
{
   return structures[ convert( coords ) ];
}

const TStructure& CMapData::operator[] ( const TCoords& coords ) const
{
   return structures[ convert( coords ) ];
}

long CMapData::convert( const TCoords& coords ) const
{
   return ( coords.y - min.y ) * ( max.x - min.x + 1 ) + ( coords.x - min.x );
}
