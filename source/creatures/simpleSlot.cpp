#include "simpleSlot.h"

using namespace creatures;
using namespace items;

CSimpleSlot::CSimpleSlot( TItemType itemType_ )
   : itemType( itemType_ )
{}

bool CSimpleSlot::canEquip( IItem::Ptr item ) const
{
   return ( item->getItemType() == itemType );
}
