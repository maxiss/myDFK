#pragma once

#include "game_export.h"
//#include "objects\IObject.h"

namespace game
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
      
      //virtual objects::IObject::Ptr selectObject( objects::TObjectList& ) = 0;

      //virtual bool isNeedSelect() = 0;
      //virtual int getIndex() = 0;
      //virtual objects::IObject::ConstPtr getObject() = 0;
      //virtual const objects::TObjectList& getFullList() = 0;
   };
}