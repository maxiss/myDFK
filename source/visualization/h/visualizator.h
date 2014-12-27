#pragma once

#include "map\h\map.h"

namespace visualization
{
   class CVisualizator
   {
   public:
      CVisualizator( const gamemap::CMap& );
      void frame();

   private:
      const gamemap::CMap& map;
      //virtual void draw( const gamemap::TPosition& pos ) = 0;
      // TODO: bear out to child class
      void draw( const gamemap::TPosition& pos );
      void initConsole();
      void draw( const gamemap::TObjectType& objType );

   };

}
