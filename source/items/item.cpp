#include "item.h"

using namespace items;
using namespace gamemap;

TObjectType CItem::getObjectType() const
{
   return TObjectType::item;
}
