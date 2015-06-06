#include "TCoords.h"
#include <tuple>

using namespace game_engine;

bool TCoords::operator < (const TCoords& other) const
{
   return std::tie( x, y ) < std::tie( other.x, other.y );
}

bool TCoords::operator == (const TCoords& other) const
{
   return std::tie( x, y ) == std::tie( other.x, other.y );
}
