#include "backpack.h"
#include "containerPosition.h"

using namespace items;

TItemType CBackPack::getItemType() const
{
   return TItemType::backpack;
}

std::string items::CBackPack::getName() const
{
   return "Backpack";
}
