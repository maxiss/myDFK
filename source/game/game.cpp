#include "game.h"
#include "map\mapPosition.h"

using namespace game;
using namespace gamemap;
using namespace objects;

// TODO: move to ini-file
const int MINX = 0;
const int MINY = 0;
const int MAXX = 20;
const int MAXY = 10;

CGame::CGame()
   : map{ std::make_shared<CMap>( TCoords{ MINX, MINY }, TCoords{ MAXX, MAXY } ) }
{}

void CGame::start()
{
   initData();
}

void CGame::addObjectToMap( IObject::Ptr object, coord x, coord y )
{
   map->place( object, TCoords{ x, y } );
}

IMap::ConstPtr CGame::getMap()
{
   return map;
}
