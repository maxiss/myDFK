#pragma once

#include "map\h\map.h"

namespace visualization
{
   class CVisualizator
   {
   public:
      CVisualizator( const gamemap::CMap& gamemap );
      void gameLoop();
      void stop();

   private:
      bool loop;
      const gamemap::CMap& map;
      void frame();
      virtual void draw( const gamemap::TPosition& pos ) = 0;

   };

}
