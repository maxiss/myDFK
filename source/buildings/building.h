#pragma once

#include "objects\IObject.h"

namespace game_engine
{
   class IBuilding : public IObject
   {
      virtual ObjectType getObjectType() const override final;
   };

}
