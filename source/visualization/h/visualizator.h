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
      void frame();
      //virtual void draw( const gamemap::TPosition& pos ) = 0;
      // TODO: bear out to child class
      void draw( const gamemap::TPosition& pos );
      void initConsole();
      void draw( const gamemap::TObjectType& objType );

   };

}
