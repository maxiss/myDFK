#pragma once

#include "map\TCoords.h"
#include "visualization\visualizator_console.h"
#include "map\map.h"
#include "creatures\creature.h"
#include "tasks\tasks.h"
#include "IPlayer.h"

namespace game
{
   class CGame
   {
   public:
      typedef std::shared_ptr< CGame > Ptr;
      typedef std::weak_ptr< CGame > WeakPtr;
      CGame();
      void start();
      IPlayer::Ptr& getPlayerInterface();

   protected:
      virtual int eventHandler( int key ) = 0;
      virtual void initData() = 0;
      virtual void step() = 0;

      void addObjectToMap( objects::IObject::Ptr, gamemap::coord x, gamemap::coord y );

   protected: // data
      IPlayer::Ptr playerInterface;

   private:
      void gameLoop();
      void _eventHandler();

   private: // data
      gamemap::CMap::Ptr map;
      visualization::CVisualizator_console visual;
      bool loop;
   };
}
