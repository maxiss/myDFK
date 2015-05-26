#pragma once
#include "game.h"
#include "creatures\dwarf.h"

namespace game
{
   class CGameDFK : public CGame
   {
   private:
      virtual void initData() override final;
      virtual game::IPlayerInterface::Ptr getPlayerInterface( IUserInterface& ) override final;

   private:
      std::shared_ptr< creatures::CDwarf > player;
   };
}
