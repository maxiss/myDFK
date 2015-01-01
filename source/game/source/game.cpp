#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"

using namespace game;
using namespace threads;
using namespace gamemap;

// TODO: move to ini-file
#define MINX 0
#define MINY 0
#define MAXX 20
#define MAXY 10
#define SLEEP_TIME 300

CGame::CGame()
   : map( MINX, MINY, MAXX, MAXY )
   , visual( map )
{
}

void CGame::start()
{
   initData();
   loop = true;
   CThread<CGame> gameLoop( this, &CGame::gameLoop );
   CThread<visualization::CVisualizator> visualLoop( &this->visual, &visualization::CVisualizator::gameLoop );
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

CObject* CGame::addObject( CObject* object )
{
   objects.add( object );
   return object;
}

CObject* CGame::addObject( CObject* object, const coord& x, const coord& y )
{
   addObject( object );
   map.addObject( object, TPoint( x, y ) );
   return object;
}

void CGame::moveObject( CObject* object, const coord& x, const coord& y )
{
   map.moveObject( object, TPoint( x, y ) );
}
