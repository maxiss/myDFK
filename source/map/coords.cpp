#include "Coords.h"
#include <tuple>

using namespace game_engine;

bool Coords::operator < (const Coords& other) const
{
   return std::tie( x, y ) < std::tie( other.x, other.y );
}

bool Coords::operator == (const Coords& other) const
{
   return std::tie( x, y ) == std::tie( other.x, other.y );
}
