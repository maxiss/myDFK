#pragma once

#include "creature.h"

namespace creatures
{
   class CDwarf : public CCreature
   {
      virtual TCreatureType getCreatureType();
   };

}