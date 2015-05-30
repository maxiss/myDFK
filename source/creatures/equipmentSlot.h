#pragma once

#include <memory>
#include <vector>
#include "items/item.h"

namespace creatures
{
	class CEquipmentPosition;
	
	class CEquipmentSlot
      : private std::enable_shared_from_this< CEquipmentSlot >
	{
	public:
      typedef std::shared_ptr< CEquipmentSlot > Ptr;
      typedef std::weak_ptr< CEquipmentSlot > WeakPtr;
	
      virtual bool canEquip( items::IItem::Ptr ) const = 0;
	   bool isEmpty() const;
	   void equip( items::IItem::Ptr );
	   items::IItem::Ptr getItem();

	private:
	   friend CEquipmentPosition;
	   void add( items::IItem::Ptr );
      void remove( items::IItem::Ptr );
	
	private:
	   items::IItem::Ptr content;
	};

   typedef std::vector< CEquipmentSlot::Ptr > TEquipmentSlots;
}
