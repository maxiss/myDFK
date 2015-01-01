#include "itemContainer.h"

using namespace gamemap;
using namespace items;

void CItemContainer::add( items::CItem* item )
{
   addObject( item );
}

void CItemContainer::remove( items::CItem* item )
{
   removeObject( item );
}
