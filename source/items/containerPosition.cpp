#include "containerPosition.h"

using namespace game_engine;

CContainerPosition::CContainerPosition( IItem::Ptr item_, CItemContainer::Ptr container_ )
   : item{ item_ }
   , container{ container_ }
{
   container_->add( item_ );
}

CContainerPosition::~CContainerPosition()
{
   auto container_ = getContainer();
   if ( !item.expired() )
      container_->remove( getItem() );
}

PositionType CContainerPosition::getPositionType() const
{
   return PositionType::Container;
}

CItemContainer::Ptr CContainerPosition::getContainer()
{
   return container.lock();
}

IItem::Ptr CContainerPosition::getItem()
{
   return item.lock();
}
