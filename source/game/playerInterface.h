#pragma once

#include "creatures/creature.h"
#include "IPlayerInterface.h"
#include "game.h"

namespace game
{
   class CPlayerInterface : public IPlayerInterface
   {
   public:
      CPlayerInterface( creatures::ICreature::Ptr, IUserInterface& );

      virtual void moveUp() override final;
      virtual void moveDown() override final;
      virtual void moveLeft() override final;
      virtual void moveRight() override final;

      virtual void pickUpItem() override final;
      virtual void dropItem() override final;

   private:
      creatures::ICreature::Ptr creature;
      IUserInterface& ui;
   };
} 
