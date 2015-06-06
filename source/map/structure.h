#pragma once

namespace game_engine
{
   enum class StructureType
   {
      None,
      Floor,
      Wall,
   };

   class TStructure
   {
   public:
      TStructure() : type( StructureType::None ) {};

      StructureType type;
   };

}
