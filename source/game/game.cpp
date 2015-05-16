#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"
#include "map\mapPosition.h"
#include "map\mapInstance.h"

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
   : map( TCoords{ MINX, MINY }, TCoords{ MAXX, MAXY } )
   , visual( map )
{
   Map::Intance().setMap( &map );
}

void CGame::start()
{
   initData();
   loop = true;
   CThread<CGame> gameLoop( this, &CGame::gameLoop );
   CThread<CVisualizator> visualLoop( &this->visual, &CVisualizator::gameLoop );
   _eventHandler();
   visual.stop();
   loop = false;
}

void CGame::_eventHandler()
{
   int key = 0;
   do
   {
      key = _getch(); // TODO: process 0-key
      key = eventHandler( key );

      key = (key == 27) ? -key : key;
   } while ( key >= 0 );
}

void CGame::gameLoop()
{
   while (loop)
   {
      step();
      Sleep( SLEEP_TIME );
   }
}

void CGame::addObjectToMap( IObject::Ptr object, coord x, coord y )
{
   object->setPosition( std::make_shared< CMapPosition >( object, TCoords{ x, y } ) ); // !!! how to remove object in make_shared ???
}

IObject::Ptr CGame::getObjectOnMap( TObjectType objType, coord x, coord y )
{
   return map.getObject( TCoords{ x, y }, objType );
}
