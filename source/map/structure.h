#pragma once

namespace game_engine
{
   enum class TStructureType
   {
      none,
      floor,
      wall,
   };

   class TStructure
   {
   public:
      TStructure() : type( TStructureType::none ) {};

      TStructureType type;
   };

}
