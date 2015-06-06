#pragma once

#include <memory>
#include <vector>
#include "items/item.h"

namespace game_engine
{
	class CEquipmentPosition;
	
	class CEquipmentSlot
      : private std::enable_shared_from_this< CEquipmentSlot >
	{
	public:
      typedef std::shared_ptr< CEquipmentSlot > Ptr;
      typedef std::weak_ptr< CEquipmentSlot > WeakPtr;
	
      virtual bool canEquip( IItem::Ptr ) const = 0;
	   bool isEmpty() const;
	   void equip( IItem::Ptr );
	   IItem::Ptr getItem();

	private:
	   friend CEquipmentPosition;
	   void add( IItem::Ptr );
      void remove( IItem::Ptr );
	
	private:
	   IItem::Ptr content;
	};

   typedef std::vector< CEquipmentSlot::Ptr > EquipmentSlots;
}
