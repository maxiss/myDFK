#pragma once

#include "visualization\h\visualisator.h"

namespace game
{
   class CGame
   {
   public:
      CGame();
      void start();
      void stop();

   private:
      visualisation::CVisualisator visual;
   };

}