#pragma once

#include "map\Coords.h"
#include "map\map.h"
#include "creatures\creature.h"
#include "tasks\tasks.h"
#include "IPlayerInterface.h"
#include "IGame.h"

namespace game_engine
{
   class CGame : public IGame
   {
   public:
      typedef std::shared_ptr< CGame > Ptr;
      typedef std::weak_ptr< CGame > WeakPtr;

      CGame();
      virtual void start() override final;
      virtual IMap::ConstPtr getMap() override final;

   protected:
      void addObjectToMap( IObject::Ptr, Coord x, Coord y );

   private:
      virtual void initData() = 0;

   private: // data
      CMap::Ptr map;
   };
}
