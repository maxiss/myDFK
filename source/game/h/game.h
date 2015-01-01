#pragma once

#include "visualization\h\visualizator_console.h"
#include "map\h\map.h"
#include "map\h\objectContainer.h"
#include "creatures\h\creature.h"

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

      CObject* addObject( CObject* object, const coord& x, const coord& y );

      CObject* getObject( const TObjectType& objType,  const coord& x, const coord& y );
      void moveObject( CObject* object, const coord& x, const coord& y );

      void creatureCarryItem( CCreature* creature );
      void creatureDropItem( CCreature* creature );

   private:
      CObjectContainer objects;
      CVisualizator_console visual;
      CMap map;

      bool loop;
      void gameLoop();
      void _eventHandler();

      void addObject( CObject* object );
      void addObjectToMap( CObject* object, const coord& x, const coord& y );
      void removeObjectFromMap( CObject* object );

   };

}
