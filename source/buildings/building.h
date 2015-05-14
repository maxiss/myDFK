#pragma once

//#include "map\object.h"
#include "objects\IObject.h"

namespace buildings
{
   class IBuilding : public objects::IObject
   {
      virtual objects::TObjectType getObjectType() const override final;
   };

}
