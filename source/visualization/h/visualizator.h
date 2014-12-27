#pragma once

#include "map\h\map.h"

namespace visualization
{
   class CVisualizator
   {
   public:
      CVisualizator( const gamemap::CMap& gamemap );
      void start();

   protected:
      void loop();

   private:
      const gamemap::CMap& map;
      void frame();
      virtual void draw( const gamemap::TPosition& pos ) = 0;

   };

}
