#include "game.h"
#include "map\mapPosition.h"

using namespace game_engine;

// TODO: move to ini-file
const int MINX = 0;
const int MINY = 0;
const int MAXX = 20;
const int MAXY = 10;

CGame::CGame()
   : map{ std::make_shared<CMap>( Coords{ MINX, MINY }, Coords{ MAXX, MAXY } ) }
{}

void CGame::start()
{
   initData();
}

void CGame::addObjectToMap( IObject::Ptr object, Coord x, Coord y )
{
   map->place( object, Coords{ x, y } );
}

IMap::ConstPtr CGame::getMap()
{
   return map;
}
