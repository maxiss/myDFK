#pragma once

#include "map\h\object.h"
#include "creatureTypes.h"

namespace creatures
{
   class CCreature : public gamemap::CObject
   {
   public:
      virtual gamemap::TObjectType getObjectType() const;
      virtual TCreatureType getCreatureType() = 0;

   };

}
