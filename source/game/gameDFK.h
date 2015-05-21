#pragma once
#include "game.h"
#include "creatures\dwarf.h"

namespace game
{
   class CGameDFK : public CGame
   {
   public:
      CGameDFK();

   protected:
      virtual int eventHandler( int key );
      virtual void initData();
      virtual void step();

   private:
      std::shared_ptr< creatures::CDwarf > player;
   };
}
