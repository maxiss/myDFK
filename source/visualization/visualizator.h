#pragma once

#include "map\map.h"

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
      bool redraw;
      const CMap& map;
      void frame();
      virtual void draw( const TMapPoint& mapPoint ) = 0;
      const TMapPointList getChanges();

   };

}
