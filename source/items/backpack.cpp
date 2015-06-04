#include "backpack.h"
#include "containerPosition.h"

using namespace game_engine;

TItemType CBackPack::getItemType() const
{
   return TItemType::backpack;
}

std::string CBackPack::getName() const
{
   return "Backpack";
}
