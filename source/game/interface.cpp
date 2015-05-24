#include "interface.h"
#include "gameDFK.h"
#include "gameInstance.h"

using namespace game;

game::CGame::Ptr startGame()
{
   auto gameInstance = std::make_shared< CGameDFK >();
   //Game::Instance().setGame( game );
   //game->start();
   return gameInstance;
}
