#pragma once
#include "game.h"
#include <list>

namespace game
{
   class CGameDFK : public CGame
   {
   protected:
      virtual int eventHandler( int key );
      virtual void initData();
      virtual void step();

   private:
      std::list< gamemap::CObject* > objects;

      gamemap::CObject* addObject( gamemap::CObject* object );
      gamemap::CObject* addObject( gamemap::CObject* object, gamemap::TPoint point );
   };

}
