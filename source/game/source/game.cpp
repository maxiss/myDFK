#include "game.h"
#include <Windows.h>
#include <conio.h>
#include "threads.h"

using namespace game;
using namespace threads;

CGame::CGame()
{
}

void CGame::gameLoop()
{
   while (loop)
   {
      step();
      Sleep(300);
   }
}

void CGame::start()
{
   loop = true;
   int ch = 0;

   CThread<CGame> gameLoop( *this, &CGame::gameLoop );
   gameLoop.run();
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
