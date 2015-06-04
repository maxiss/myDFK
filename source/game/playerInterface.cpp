#include "playerInterface.h"
#include "map\mapPosition.h"
#include "items\item.h"

using namespace game_engine;

CPlayerInterface::CPlayerInterface( ICreature::Ptr creature_, IUserInterface& ui_ )
   : creature{ creature_ }
   , ui{ ui_ }
{}

void CPlayerInterface::moveUp()
{
   creature->move( +0, -1 );
}

void CPlayerInterface::moveDown()
{
   creature->move( +0, +1 );
}

void CPlayerInterface::moveLeft()
{
   creature->move( -1, +0 );
}

void CPlayerInterface::moveRight()
{
   creature->move( +1, +0 );
}

void CPlayerInterface::pickUpItem()
{
   auto position = creature->getPosition();
   if ( position && position->getPositionType() == TPositionType::map  )
   {
      auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
      const auto& coords = mapPosition->getCoords();
      auto map = mapPosition->getMap();

      auto objects = map->getObjects( coords, TObjectType::item );

      if ( !objects.empty() )
      {
         auto obj = ui.select( makeNameableVector( objects ) );
         if ( obj )
         {
	         auto item = std::dynamic_pointer_cast<IItem>(obj);
	         creature->carryItem( item );
         }
      }
   }
}

void CPlayerInterface::dropItem()
{
   auto position = creature->getPosition();
   if ( position && position->getPositionType() == TPositionType::map  )
   {
      auto items = creature->getStorageItems();

      if ( !items.empty() )
      {
         auto obj = ui.select( makeNameableVector( items ) );
         if ( obj )
         {
            auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
            auto map = mapPosition->getMap();
            const auto& coords = mapPosition->getCoords();

	         auto item = std::dynamic_pointer_cast<IItem>(obj);
            map->place( item, coords );
         }
      }
   }
}

void CPlayerInterface::equipItem()
{
   auto position = creature->getPosition();
   if ( position && position->getPositionType() == TPositionType::map )
   {
      auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
      const auto& coords = mapPosition->getCoords();
      auto map = mapPosition->getMap();

      auto objects = map->getObjects( coords, TObjectType::item );
      if ( !objects.empty() )
      {
         auto object = ui.select( makeNameableVector( objects ) );
         if ( object )
         {
            auto item = std::dynamic_pointer_cast<IItem>(object);
            creature->equip( item );
         }
      }
   }
}

void CPlayerInterface::takeOffItem()
{
   auto position = creature->getPosition();
   if ( position && position->getPositionType() == TPositionType::map  )
   {
      auto items = creature->getEquipedItems();

      if ( !items.empty() )
      {
         auto obj = ui.select( makeNameableVector( items ) );
         if ( obj )
         {
            auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
            auto map = mapPosition->getMap();
            const auto& coords = mapPosition->getCoords();

	         auto item = std::dynamic_pointer_cast<IItem>(obj);
            map->place( item, coords );
         }
      }
   }
}
