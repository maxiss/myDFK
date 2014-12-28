#pragma once

#include "visualization\h\visualizator_console.h"
#include "map\h\map.h"

namespace game
{
   class CGame
   {
   public:
      CGame();
      void start();

   protected:
      void gameLoop();
      int eventHandler( int key );
      void addObject( const gamemap::TObjectType& objType, const gamemap::TPoint& pos );

   private:
      visualization::CVisualizator_console visual;
      gamemap::CMap map;

      bool loop;
      void step();

   };

}
