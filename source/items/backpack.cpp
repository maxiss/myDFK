#include "backpack.h"
#include "containerPosition.h"

using namespace game_engine;

ItemType CBackPack::getItemType() const
{
   return ItemType::Backpack;
}

std::string CBackPack::getName() const
{
   return "Backpack";
}
