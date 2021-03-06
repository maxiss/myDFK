#pragma once

#include "creature.h"

namespace game_engine
{
   class CDwarf final
      : public ICreature
   {
   public:
      CDwarf();
      virtual CreatureType getCreatureType() const override final;
      virtual std::string getName() const override;
   };

}