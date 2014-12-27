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

void CGame::gameLoop()
{
   while (loop)
   {
      step();
      Sleep( SLEEP_TIME );
   }
}

void CGame::start()
{
   loop = true;
   int ch = 0;

   CThread<CGame> gameLoop( *this, &CGame::gameLoop );
   gameLoop.run();

   CThread<visualization::CVisualizator> visualLoop( visual, &visualization::CVisualizator::loop );
   visualLoop.run();

   do
   {
      ch = _getch();
   } while ( ch != 27 );
   loop = false;
}

void CGame::step()
{
}
