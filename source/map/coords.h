#pragma once

#include <cstdint>

namespace game_engine
{
   typedef int16_t Coord;

   struct Coords
   {
      Coord x;
      Coord y;

      bool operator < (const Coords&) const;
      bool operator == (const Coords&) const;
   };
}
