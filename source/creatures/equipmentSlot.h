#pragma once

#include <memory>
#include "items/item.h"

namespace items
{
	class CEquipmentPosition;
	
	class CEquipmentSlot
      : private std::enable_shared_from_this< CEquipmentSlot >
	{
	public:
      typedef std::shared_ptr< CEquipmentSlot > Ptr;
      typedef std::weak_ptr< CEquipmentSlot > WeakPtr;
	
      virtual bool canEquip( IItem::Ptr ) = 0;
	   bool isEmpty() const;
	   void equip( IItem::Ptr );
      void takeOff( IItem::Ptr );
	
	   IItem::Ptr getObject();

	private:
	   friend CEquipmentPosition;
	   void _equip( IItem::Ptr );
	
	private:
	   IItem::Ptr content;
	
	};
}
