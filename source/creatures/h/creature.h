#pragma once

#include "map\h\object.h"
#include "creatureTypes.h"

namespace creatures
{
   class CCreature : public gamemap::CObject
   {
   public:
      virtual TCreatureType getCreatureType() = 0;

   };

}
