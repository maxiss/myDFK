#include "itemContainer.h"
#include "containerPosition.h"

using namespace game_engine;

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

ItemList CItemContainer::getItems()
{
   ItemList items;
   for ( const auto& it : content )
      items.push_back( it.second );
   return items;
}

void CItemContainer::store( IItem::Ptr item )
{
   item->setPosition( std::make_shared<CContainerPosition>( item, shared_from_this() ) );
}
