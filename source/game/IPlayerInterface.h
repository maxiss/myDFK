#pragma once

#include <memory>
#include "game_export.h"

namespace game_engine
{
   class GAME_EXPORT IPlayerInterface
   {
   public:
      typedef std::shared_ptr< IPlayerInterface > Ptr;

      virtual void moveUp() = 0;
      virtual void moveDown() = 0;
      virtual void moveLeft() = 0;
      virtual void moveRight() = 0;

      virtual void pickUpItem() = 0;
      virtual void dropItem() = 0;
      virtual void equipItem() = 0;
      virtual void takeOffItem() = 0;
   };
}