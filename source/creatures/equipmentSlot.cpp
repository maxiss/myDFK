#include "equipmentSlot.h"
#include "equipmentPosition.h"

using namespace items;

bool CEquipmentSlot::isEmpty() const
{
   return bool( content );
}

void CEquipmentSlot::equip( IItem::Ptr item )
{
   if ( canEquip( item ) && !isEmpty() )
      item->setPosition( std::make_shared< CEquipmentPosition >( item, shared_from_this() ) );
}

IItem::Ptr CEquipmentSlot::getObject()
{
   return content;
}

void CEquipmentSlot::_equip( IItem::Ptr item )
{
   // ASSERT( !content ); !!!
   content = item;
}

void items::CEquipmentSlot::takeOff( IItem::Ptr item )
{
   if ( content == item )
      content.reset();
}
