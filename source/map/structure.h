#pragma once

namespace gamemap
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
