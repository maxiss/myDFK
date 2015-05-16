#include "mapInstance.h"

using namespace gamemap;

Map::Map()
{}

Map& Map::Intance()
{
   static Map mapInstance;
   return mapInstance;
}

void Map::setMap( CMap* map_ )
{
   map = map_;
}

CMap& Map::getMap()
{
   _ASSERT( map != nullptr );
   return *map;
}
