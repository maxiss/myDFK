#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"

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
   loop = true;
   int key = 0;

   CThread<CGame> gameLoop( this, &CGame::gameLoop );
   CThread<visualization::CVisualizator> visualLoop( &this->visual, &visualization::CVisualizator::gameLoop );
   do
   {
      key = _getch();
      key = eventHandler( key );
   } while ( key >= 0 );
   visual.stop();
   loop = false;
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

// TODO: bare out key mapping to other class
int CGame::eventHandler( int key )
{
   switch (key)
   {
      case 27 :
         key = -key;
      break;

   }
   return key;
}
