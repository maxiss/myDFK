#pragma once

#include "map\TCoords.h"
#include "map\map.h"
#include "creatures\creature.h"
#include "tasks\tasks.h"
#include "IPlayerInterface.h"
#include "IGame.h"

namespace game
{
   class CGame : public IGame
   {
   public:
      typedef std::shared_ptr< CGame > Ptr;
      typedef std::weak_ptr< CGame > WeakPtr;

      CGame();
      virtual void start() override final;
      virtual gamemap::IMap::ConstPtr getMap() override final;

   protected:
      void addObjectToMap( objects::IObject::Ptr, gamemap::coord x, gamemap::coord y );

   private:
      virtual void initData() = 0;

   private: // data
      gamemap::CMap::Ptr map;
   };
}
