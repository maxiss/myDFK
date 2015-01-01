#include "itemContainer.h"

using namespace gamemap;
using namespace items;

void CItemContainer::add( CItem* item )
{
   addObject( item );
}

void CItemContainer::remove( CItem* item )
{
   removeObject( item );
}
