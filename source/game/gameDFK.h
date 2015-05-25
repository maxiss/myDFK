#pragma once
#include "game.h"
#include "creatures\dwarf.h"

namespace game
{
   class CGameDFK : public CGame
   {
   private:
      virtual void initData();

   private:
      std::shared_ptr< creatures::CDwarf > player;
   };
}
