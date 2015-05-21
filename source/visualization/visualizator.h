#pragma once

#include "map\map.h"

namespace visualization
{
   class CVisualizator
   {
   public:
      CVisualizator( gamemap::CMap::ConstPtr );
      void gameLoop();
      void stop();

   private:
      void frame();
      virtual void draw( const gamemap::TMapPoint& mapPoint ) = 0;
      virtual void drawPlayerInterface() = 0;
      const gamemap::TMapPointList getChanges();

   private: // data
      bool loop;
      bool redraw;
      gamemap::CMap::ConstPtr map;

   };

}
