#pragma once

#include "creatures/creature.h"
#include "IPlayerInterface.h"
#include "game.h"

namespace game
{
   class CPlayerInterface : public IPlayerInterface
   {
   public:
      CPlayerInterface( creatures::ICreature::Ptr/*, game::CGame::Ptr*/ );

      virtual void moveUp() override final;
      virtual void moveDown() override final;
      virtual void moveLeft() override final;
      virtual void moveRight() override final;

      virtual void pickUpItem() override final;
      virtual void dropItem() override final;

      //virtual objects::IObject::Ptr selectObject( objects::TObjectList& ) override final;
      //virtual bool isNeedSelect() override final;
      //virtual int getIndex() override final;
      //virtual objects::IObject::ConstPtr getObject() override final;
      //virtual const objects::TObjectList& getFullList() override final;

   private:
      creatures::ICreature::Ptr creature;
      //game::CGame::WeakPtr game;
      


      //int eventHandler( int key );
      //objects::TObjectList list;
      //objects::TObjectList::iterator listIterator;
      //int index;
      //bool needSelect;
   };
} 
