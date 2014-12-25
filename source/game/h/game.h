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
      void stop();

   private:
      visualization::CVisualizator visual;
      map::CMap map;

   };

}
