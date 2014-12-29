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
      virtual int eventHandler( int key ) = 0;
      virtual void initData() = 0;
      void addObject( gamemap::CObject* obj, const gamemap::TPoint& pos );

   private:
      visualization::CVisualizator_console visual;
      gamemap::CMap map;

      bool loop;
      void gameLoop();
      void step();
      void _eventHandler();


   };

   class CGameDFK : public CGame
   {
   protected:
      virtual int eventHandler( int key );
      virtual void initData();
   };
}
