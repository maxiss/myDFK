#pragma once

#include "visualization\h\visualizator.h"
#include "map\h\map.h"

namespace game
{
   class CGame
   {
   public:
      CGame();
      void start();

   protected:
      void gameLoop();

   private:
      visualization::CVisualizator visual;
      gamemap::CMap map;

      bool loop;
      void step();

   };

}
