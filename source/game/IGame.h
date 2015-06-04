#pragma once

#include <memory>
#include "game_export.h"
#include "map/IMap.h"
#include "IPlayerInterface.h"
#include "IUserInterface.h"

namespace game_engine
{
   class GAME_EXPORT IGame
   {
   public:
      typedef std::shared_ptr< IGame > Ptr;
      virtual void start() = 0;
      virtual IMap::ConstPtr getMap() = 0;
      virtual IPlayerInterface::Ptr getPlayerInterface( IUserInterface& ) = 0;
   };
}
