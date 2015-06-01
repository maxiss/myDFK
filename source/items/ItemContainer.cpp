#include "itemContainer.h"
#include "containerPosition.h"

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

TItemList CItemContainer::getItems()
{
   TItemList items;
   for ( const auto& it : content )
      items.push_back( it.second );
   return items;
}

void CItemContainer::store( IItem::Ptr item )
{
   item->setPosition( std::make_shared<CContainerPosition>( item, shared_from_this() ) );
}
