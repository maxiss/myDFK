#pragma once

#include "map\h\map.h"

namespace visualization
{
   using namespace gamemap;

   class CVisualizator
   {
   public:
      CVisualizator( const CMap& gamemap );
      void gameLoop();
      void stop();

   private:
      bool loop;
      const CMap& map;
      void frame();
      virtual void draw( const TMapPoint& mapPoint ) = 0;

   };

}
