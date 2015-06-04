#include "weapon.h"

using namespace game_engine;

TItemType CWeapon::getItemType() const 
{
   return TItemType::weapon;
}

std::string CWeapon::getName() const
{
   return "Weapon";
}
