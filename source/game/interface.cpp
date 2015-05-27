#include "interface.h"
#include "gameDFK.h"

using namespace game;

IGame::Ptr startGame()
{
   auto gameInstance = std::make_shared< CGameDFK >();
   gameInstance->start();
   return gameInstance;
}
