#pragma once

#include "map\TCoords.h"
#include "visualization\visualizator_console.h"
#include "map\map.h"
#include "creatures\creature.h"
#include "tasks\tasks.h"

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
      virtual void step() = 0;

      void addObjectToMap( objects::IObject::Ptr, gamemap::coord x, gamemap::coord y );
      objects::IObject::Ptr getObjectOnMap( objects::TObjectType, gamemap::coord x, gamemap::coord y );

   private:
      void gameLoop();
      void _eventHandler();

   private: // data
      gamemap::CMap::Ptr map;
      visualization::CVisualizator_console visual;
      bool loop;

   };
}
