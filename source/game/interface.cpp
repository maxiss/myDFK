#include "interface.h"
#include "gameDFK.h"
#include "gameInstance.h"

using namespace game;

void startGame()
{
   auto game = std::make_shared< CGameDFK >();
   Game::Instance().setGame( game );
   game->start();
}
