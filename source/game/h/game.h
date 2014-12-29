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
      gamemap::CMap map;

      virtual int eventHandler( int key ) = 0;
      virtual void initData() = 0;
      virtual void step() = 0;

   private:
      visualization::CVisualizator_console visual;

      bool loop;
      void gameLoop();
      void _eventHandler();

   };

}
