#pragma once

#include "visualization\h\visualizator_console.h"
#include "map\h\map.h"

namespace game
{
   class CGame
   {
   public:
      CGame();
      void start();

   protected:
      virtual int eventHandler( int key ) = 0;
      virtual void initData() = 0;
      virtual void step() = 0;

      gamemap::CObject* addObject( gamemap::CObject* object, const gamemap::coord& x, const gamemap::coord& y );
      void moveObject( gamemap::CObject* object, const gamemap::coord& x, const gamemap::coord& y );

   private:
      std::list< gamemap::CObject* > objects;
      visualization::CVisualizator_console visual;
      gamemap::CMap map;

      bool loop;
      void gameLoop();
      void _eventHandler();
      gamemap::CObject* addObject( gamemap::CObject* object );

   };

}
