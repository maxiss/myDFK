#pragma once

#include "map\point.h"
#include "visualization\visualizator_console.h"
#include "map\map.h"
//#include "map\objectContainer.h"
//#include "objects\ObjectContainer.h"
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

      IObject::Ptr addObject( IObject::Ptr object, coord x, coord y );
      IObject::Ptr getObject( TObjectType objType, coord x, coord y );
      void moveObject( IObject::Ptr object, coord x, coord y );

      void creatureCarryItem( ICreature::Ptr creature );
      void creatureDropItem( ICreature::Ptr creature );

   private:
      CMap map;
      CVisualizator_console visual;

      bool loop;
      void gameLoop();
      void _eventHandler();

      void addObjectToMap( IObject::Ptr object, coord x, coord y );
      void removeObjectFromMap( IObject::Ptr object );

   };

}