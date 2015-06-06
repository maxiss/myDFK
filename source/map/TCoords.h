#pragma once

#include <cstdint>

namespace game_engine
{
   typedef uint16_t coord;

   struct TCoords
   {
      coord x;
      coord y;

      bool operator < (const TCoords&) const;
      bool operator == (const TCoords&) const;
   };
}
