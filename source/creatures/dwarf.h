#pragma once

#include "creature.h"

namespace creatures
{
   class CDwarf /*final*/ : public ICreature
   {
      virtual TCreatureType getCreatureType() const override final;
   };

}