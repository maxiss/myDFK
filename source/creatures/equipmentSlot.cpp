#include "equipmentSlot.h"
#include "equipmentPosition.h"

using namespace creatures;
using namespace items;

bool CEquipmentSlot::isEmpty() const
{
   return !content;
}

void CEquipmentSlot::equip( IItem::Ptr item )
{
   if ( canEquip( item ) && isEmpty() )
      item->setPosition( std::make_shared< CEquipmentPosition >( item, shared_from_this() ) );
}

IItem::Ptr CEquipmentSlot::getItem()
{
   return content;
}

void CEquipmentSlot::add( IItem::Ptr item )
{
   //if ( canEquip( item ) && isEmpty() ) // !!!
   content = item;
}

void CEquipmentSlot::remove( IItem::Ptr item )
{
   if ( content == item )
      content.reset();
}
