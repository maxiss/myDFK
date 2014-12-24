#pragma once

#include "creatureTypes.h"

namespace creatures
{
   class CCreature
   {
   public:
      virtual TCreatureType getCreatureType() = 0;

   };

}