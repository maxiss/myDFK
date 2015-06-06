#include "weapon.h"

using namespace game_engine;

ItemType CWeapon::getItemType() const 
{
   return ItemType::Weapon;
}

std::string CWeapon::getName() const
{
   return "Weapon";
}
