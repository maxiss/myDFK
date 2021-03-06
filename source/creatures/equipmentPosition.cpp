#include "equipmentPosition.h"

using namespace game_engine;

PositionType CEquipmentPosition::getPositionType() const
{
   return PositionType::EquipmentSlot;
}

CEquipmentPosition::CEquipmentPosition( IItem::Ptr item_, CEquipmentSlot::Ptr slot_ )
   : item{ item_ }, slot{ slot_ }
{
   slot_->add( item_ );
}

CEquipmentPosition::~CEquipmentPosition()
{
   auto slot_ = getEquipmentSlot();
   if ( slot_ )
      slot_->remove( getItem() );
}

CEquipmentSlot::Ptr CEquipmentPosition::getEquipmentSlot()
{
   return slot.lock();
}

IItem::Ptr CEquipmentPosition::getItem()
{
   return item.lock();
}
