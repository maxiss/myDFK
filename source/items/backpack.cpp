#include "backpack.h"
#include "containerPosition.h"

using namespace items;

CBackPack::CBackPack()
   : content{ new CItemContainer }
{}

IItem::Ptr CBackPack::get()
{
   return content->get();
}

void CBackPack::store( IItem::Ptr item )
{
   item->setPosition( std::make_shared<CContainerPosition>( item, content ) );
}

bool CBackPack::isEmpty() const
{
   return content->isEmpty();
}

TItemType CBackPack::getItemType() const
{
   return TItemType::backpack;
}
