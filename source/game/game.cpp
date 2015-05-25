#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"
#include "map\mapPosition.h"

using namespace game;
using namespace threads;
using namespace gamemap;
using namespace visualization;
using namespace objects;

// TODO: move to ini-file
const int MINX = 0;
const int MINY = 0;
const int MAXX = 20;
const int MAXY = 10;
const int SLEEP_TIME = 300;

CGame::CGame()
   : map( std::make_shared<CMap>( TCoords{ MINX, MINY }, TCoords{ MAXX, MAXY } ) )
{}

void CGame::start()
{
   initData();
}

void CGame::addObjectToMap( IObject::Ptr object, coord x, coord y )
{
   object->setPosition( std::make_shared< CMapPosition >( object, map, TCoords{ x, y } ) ); // !!! how to remove object in make_shared ???
}

//IPlayer::Ptr& CGame::getPlayerInterface()
//{
//   return playerInterface;
//}

gamemap::IMap::ConstPtr game::CGame::getMap()
{
   return map;
}
