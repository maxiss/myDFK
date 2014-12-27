#pragma once

#include "map\h\map.h"

namespace visualization
{
   class CVisualizator
   {
   public:
      CVisualizator( const gamemap::CMap& );
      void loop();

   private:
      const gamemap::CMap& map;
   };

}
