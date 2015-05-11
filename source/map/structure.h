#pragma once

namespace gamemap
{
   enum TStructureType
   {
      STRUCTURE_NONE
    , STRUCTURE_FLOOR
    , STRUCTURE_WALL
   };

   class TStructure
   {
   public:
      TStructure() : type( STRUCTURE_NONE ) {};

      TStructureType type;
   };

}
