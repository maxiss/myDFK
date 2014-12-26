#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"

using namespace game;
using namespace threads;

CGame::CGame()
{
}

static void gameStep( CGame* data )
{
   CGame& game = *(CGame*) data;

   while (game.loop)
   {
      game.step();
      Sleep(300);
   }
}

void CGame::start()
{
   loop = true;
   int ch = 0;
   CThread<CGame> gameLoop( gameStep, this );
   do
   {
      ch = _getch();
   } while ( ch != 27 );
   loop = false;
}

int CGame::step()
{
   map.loop();
   visual.loop();
   return 0;
}
