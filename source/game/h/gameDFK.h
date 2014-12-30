#pragma once
#include "game.h"
#include "creatures\h\dwarf.h"

namespace game
{
   class CGameDFK : public CGame
   {
   protected:
      virtual int eventHandler( int key );
      virtual void initData();
      virtual void step();

   private:
      creatures::CDwarf* player;

   };

}
