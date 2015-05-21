#include "mapData.h"

using namespace gamemap;
using namespace objects;

CMapData::CMapData( const TCoords& min_, const TCoords& max_ )
   : min(min_), max(max_)
   , structures( min, max )
   , coordIndex( min, max )
{
}

void CMapData::addObject( IObject::Ptr object, const TCoords& coords )
{
   const IObject* objId = object.get();
   content.insert( make_pair( objId, object ) );

   objectCoordIndex[ objId ] = coords;
   coordIndex[ coords ].insert( objId );
}

void CMapData::removeObject( IObject::Ptr obj )
{
   const IObject* objId = obj.get();
   const TCoords coords = objectCoordIndex[ objId ];

   coordIndex[ coords ].erase( objId );
   objectCoordIndex.erase( objId );
   content.erase( objId );
}

void CMapData::updateObject( IObject::Ptr object, const TCoords& coords )
{
   const IObject* objId = object.get();
   const TCoords oldCoords = objectCoordIndex[ objId ];
   coordIndex[ oldCoords ].erase( objId );

   objectCoordIndex[ objId ] = coords;
   coordIndex[ coords ].insert( objId );
}

const TCoords& CMapData::getObjectCoords( IObject::Ptr object ) const
{
   const IObject* objId = object.get();
   auto it = objectCoordIndex.find( objId );
   if ( it != objectCoordIndex.end() )
      return it->second;
   else
      throw std::exception( "objectCoordIndex no index" );
}

TObjectList CMapData::getObjectList( const TCoords& coords, TObjectType objectType_, size_t count )
{
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

TStructure& CMapData::getStructure( const TCoords& coords )
{
   return structures[ coords ];
}

const TStructure& CMapData::getStructure( const TCoords& coords ) const
{
   return structures[ coords ];
}
