#pragma once

#include "objects\IObject.h"

namespace game
{
   class IPlayer
   {
   public:
      typedef std::shared_ptr< IPlayer > Ptr;
      
      virtual objects::IObject::Ptr selectObject( objects::TObjectList& ) = 0;

      virtual bool isNeedSelect() = 0;
      virtual int getIndex() = 0;
      virtual objects::IObject::ConstPtr getObject() = 0;
      virtual const objects::TObjectList& getFullList() = 0;
   };
}