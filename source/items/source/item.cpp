#include "item.h"

using namespace items;
using namespace gamemap;

gamemap::TObjectType CItem::getObjectType() const
{
   return OBJ_TYPE_ITEM;
}
