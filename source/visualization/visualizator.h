#pragma once

#include "map\map.h"

namespace visualization
{
   using namespace gamemap;

   class CVisualizator
   {
   public:
      CVisualizator( CMap::ConstPtr );
      void gameLoop();
      void stop();

   private:
      void frame();
      virtual void draw( const TMapPoint& mapPoint ) = 0;
      const TMapPointList getChanges();

   private: // data
      bool loop;
      bool redraw;
      CMap::ConstPtr map;

   };

}
