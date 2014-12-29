#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"

#include "map\h\objects.h"

using namespace game;
using namespace threads;

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

void CGame::step()
{
}

void CGame::addObject( gamemap::CObject* obj, const gamemap::TPoint& pos )
{
   map.addObject( obj, pos );
}


// TODO: move to another file


void CGameDFK::initData()
{

}

// TODO: bare out key mapping to other class
int CGameDFK::eventHandler( int key )
{
   switch (key)
   {
      case 32 :
         addObject( new items::CWeapon, gamemap::TPoint( 5, 5 ) ); 
      break;

      case 113 :
         addObject( new creatures::CDwarf, gamemap::TPoint( 1, 1 ) ); 
      break;

   }
   return key;
}
