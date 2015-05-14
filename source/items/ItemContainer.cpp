#include "itemContainer.h"

using namespace items;

IItem::Ptr CItemContainer::get() const 
{
   return *content.begin();
}

void CItemContainer::add( IItem::Ptr item )
{
   content.push_back( item );
}

void CItemContainer::remove( IItem::Ptr item )
{
   content.remove( item );
}

bool CItemContainer::isEmpty() const
{
   return content.empty();
}
