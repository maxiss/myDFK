#pragma once

#include <memory>
#include "game_export.h"
#include "map/IMap.h"

namespace game
{
   class GAME_EXPORT IGame
   {
   public:
      typedef std::shared_ptr< IGame > Ptr;
      virtual void start() = 0;
      virtual gamemap::IMap::ConstPtr getMap() = 0;
      //IPlayer::Ptr& getPlayerInterface(); // !!!
   };
}
