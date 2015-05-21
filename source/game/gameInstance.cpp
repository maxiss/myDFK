#include "gameInstance.h"

using namespace game;

Game::Game()
{}

Game& Game::Instance()
{
   static Game instance;
   return instance;
}

void Game::setGame( CGame::Ptr game_ )
{
   game = game_;
}

CGame::Ptr Game::getGame()
{
   return game.lock();
}

CGame::Ptr game::getGame()
{
   return Game::Instance().getGame();
}