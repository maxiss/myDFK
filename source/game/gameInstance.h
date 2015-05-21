#pragma once

#include "game.h"

namespace game
{
	class Game
	{
	public:
	   static Game& Instance();
	   void setGame( CGame::Ptr game_ );
      CGame::Ptr getGame();
	
   private:
      Game();
      CGame::WeakPtr game;
	};

   CGame::Ptr getGame();
}


