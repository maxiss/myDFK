#pragma once

#include "map\TCoords.h"
#include "visualization\visualizator_console.h"
#include "map\map.h"
#include "creatures\creature.h"
#include "tasks\tasks.h"

namespace game
{
   using namespace gamemap;
   using namespace visualization;
   using namespace creatures;

   class CGame
   {
   public:
      CGame();
      void start();

   protected:
      virtual int eventHandler( int key ) = 0;
      virtual void initData() = 0;
      virtual void step() = 0;

      void addObjectToMap( IObject::Ptr object, coord x, coord y );
      IObject::Ptr getObjectOnMap( TObjectType objType, coord x, coord y );

   private:
      void gameLoop();
      void _eventHandler();

   private: // data
      CMap::Ptr map;
      CVisualizator_console visual;
      bool loop;

   };

}
