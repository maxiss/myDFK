#include "item.h"

using namespace items;
using namespace objects;

TObjectType IItem::getObjectType() const
{
   return TObjectType::item;
}
