#pragma once

#include "IPlayerInterface.h"
#include "IUserInterface.h"
#include "creatures/creature.h"

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
      virtual void equipItem() override final;
      virtual void takeOffItem() override;

   private:
      creatures::ICreature::Ptr creature;
      IUserInterface& ui;
   };
} 
