#pragma once

#include "objects\IObject.h"

namespace game_engine
{
   class IBuilding : public IObject
   {
      virtual TObjectType getObjectType() const override final;
   };

}
