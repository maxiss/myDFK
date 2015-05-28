#include "weapon.h"

using namespace items;

TItemType CWeapon::getItemType() const 
{
   return TItemType::weapon;
}

std::string items::CWeapon::getName() const
{
   return "Weapon";
}
