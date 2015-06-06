#include "simpleSlot.h"

using namespace game_engine;

CSimpleSlot::CSimpleSlot( ItemType itemType_ )
   : itemType( itemType_ )
{}

bool CSimpleSlot::canEquip( IItem::Ptr item ) const
{
   return ( item->getItemType() == itemType );
}
