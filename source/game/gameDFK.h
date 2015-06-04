#pragma once

#include "game.h"
#include "creatures\dwarf.h"

namespace game_engine
{
   class CGameDFK : public CGame
   {
   private:
      virtual void initData() override final;
      virtual IPlayerInterface::Ptr getPlayerInterface( IUserInterface& ) override final;

   private:
      std::shared_ptr< CDwarf > player;
   };
}
