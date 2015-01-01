#include "itemContainer.h"

using namespace gamemap;
using namespace items;

CItem* CItemContainer::get()
{
   return reinterpret_cast <CItem*> ( getObject() );
}

void CItemContainer::add( CItem* item )
{
   addObject( item );
}

void CItemContainer::remove( CItem* item )
{
   removeObject( item );
}
