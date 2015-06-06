#include "mapData.h"

using namespace game_engine;

CMapData::CMapData( const Coords& min_, const Coords& max_ )
   : min(min_), max(max_)
   , structures( min, max )
   , coordIndex( min, max )
{
}

void CMapData::addObject( IObject::Ptr object, const Coords& coords )
{
   const IObject* objId = object.get();
   content.insert( make_pair( objId, object ) );

   objectCoordIndex[ objId ] = coords;
   coordIndex[ coords ].insert( objId );
}

void CMapData::removeObject( IObject::Ptr obj )
{
   const IObject* objId = obj.get();
   const Coords coords = objectCoordIndex[ objId ];

   coordIndex[ coords ].erase( objId );
   objectCoordIndex.erase( objId );
   content.erase( objId );
}

void CMapData::updateObject( IObject::Ptr object, const Coords& coords )
{
   const IObject* objId = object.get();
   const Coords oldCoords = objectCoordIndex[ objId ];
   coordIndex[ oldCoords ].erase( objId );

   objectCoordIndex[ objId ] = coords;
   coordIndex[ coords ].insert( objId );
}

const Coords& CMapData::getObjectCoords( IObject::Ptr object ) const
{
   const IObject* objId = object.get();
   auto it = objectCoordIndex.find( objId );
   if ( it != objectCoordIndex.end() )
      return it->second;
   else
      throw std::exception( "objectCoordIndex no index" );
}

ObjectList CMapData::getObjectList( const Coords& coords, ObjectType objectType_, size_t count )
{
   ObjectList retVal;

   const auto& objectIdSet = coordIndex[ coords ];
   for ( const auto it : objectIdSet )
   {
      auto object = content.find( it );
      if ( object != content.end() )
      {
         ObjectType objectType = object->second->getObjectType();
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

ConstObjectList CMapData::getConstObjectList( const Coords& coords, ObjectType objectType_, size_t count ) const
{
   ConstObjectList retVal;

   const auto& objectIdSet = coordIndex[ coords ];
   for ( const auto it: objectIdSet )
   {
      auto object = content.find( it );
      if ( object != content.end() )
      {
         ObjectType objectType = object->second->getObjectType();
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

TStructure& CMapData::getStructure( const Coords& coords )
{
   return structures[ coords ];
}

const TStructure& CMapData::getStructure( const Coords& coords ) const
{
   return structures[ coords ];
}
