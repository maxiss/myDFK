#pragma once
#include "game.h"
#include "creatures\dwarf.h"

namespace game
{
   using namespace creatures;

   class CGameDFK : public CGame
   {
   protected:
      virtual int eventHandler( int key );
      virtual void initData();
      virtual void step();

   private:
      std::shared_ptr< CDwarf > player;

   };

}
