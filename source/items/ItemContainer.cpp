#include "itemContainer.h"

using namespace items;

void CItemContainer::add( IItem::Ptr item )
{
   content[ item.get() ] = item;
}

void CItemContainer::remove( IItem::Ptr item )
{
   content.erase( item.get() );
}

bool CItemContainer::isEmpty() const
{
   return content.empty();
}

IItem::Ptr CItemContainer::get()
{
   if ( !content.empty() )
      return content.begin()->second;
   else
      return nullptr;
}
