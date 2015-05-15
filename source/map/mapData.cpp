#include "mapData.h"

using namespace gamemap;
using namespace objects;

CMapData::CMapData( const TCoords& min_, const TCoords& max_ )
   : min(min_), max(max_)
   , structures( min, max )
   , coordIndex( min, max )
{
}

void CMapData::addObject( objects::IObject::Ptr obj )
{
   const IObject* objId = obj.get();
   content.insert( make_pair( objId, obj ) );

   const TCoords coords = obj->getCoords();
   objectCoordIndex[ objId ] = coords;
   coordIndex[ coords ].insert( objId );
}

void CMapData::removeObject( objects::IObject::Ptr obj )
{
   const IObject* objId = obj.get();
   const TCoords coords = objectCoordIndex[ objId ];

   coordIndex[ coords ].erase( objId );
   objectCoordIndex.erase( objId );
   content.erase( objId );
}

void CMapData::updateObject( objects::IObject::Ptr obj )
{
   const IObject* objId = obj.get();
   const TCoords oldCoords = objectCoordIndex[ objId ];
   coordIndex[ oldCoords ].erase( objId );

   const TCoords newCoords = obj->getCoords();
   objectCoordIndex[ objId ] = newCoords;
   coordIndex[ newCoords ].insert( objId );
}

TObjectList CMapData::getObjectList( const TCoords& coords, TObjectType objectType_, size_t count )
{
   _ASSERT( count > 0 );
   TObjectList retVal;

   const auto& objectIdSet = coordIndex[ coords ];
   for ( const auto it : objectIdSet )
   {
      auto object = content.find( it );
      if ( object != content.end() )
      {
         TObjectType objectType = object->second->getObjectType();
         if ( matchObjectType( objectType, objectType_ ) )
         {
            retVal.push_back( object->second );
            if ( retVal.size() == count )
               break;
         }
      }
   }

   return retVal;
}

TConstObjectList CMapData::getConstObjectList( const TCoords& coords, TObjectType objectType_, size_t count ) const
{
   _ASSERT( count > 0 );
   TConstObjectList retVal;

   const auto& objectIdSet = coordIndex[ coords ];
   for ( const auto it: objectIdSet )
   {
      auto object = content.find( it );
      if ( object != content.end() )
      {
         TObjectType objectType = object->second->getObjectType();
         if ( matchObjectType( objectType, objectType_ ) )
         {
            retVal.push_back( object->second );
            if ( retVal.size() == count )
               break;
         }
      }
   }

   return retVal;
}

TStructure& gamemap::CMapData::getStructure( const TCoords& coords )
{
   return structures[ coords ];
}

const TStructure& gamemap::CMapData::getStructure( const TCoords& coords ) const
{
   return structures[ coords ];
}
