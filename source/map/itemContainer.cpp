#include "itemContainer.h"

using namespace gamemap;
using namespace items;

CItem* CItemContainer::get()
{
   return reinterpret_cast <CItem*> ( CObjectContainer::get() );
}

void CItemContainer::add( CItem* item )
{
   CObjectContainer::add( item );
}

void CItemContainer::remove( CItem* item )
{
   CObjectContainer::remove( item );
}
