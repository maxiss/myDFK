#pragma once

#include "creature.h"

namespace creatures
{
   class CDwarf final
      : public ICreature
   {
   public:
      CDwarf();
      virtual TCreatureType getCreatureType() const override final;
      virtual std::string getName() const override;
   };

}