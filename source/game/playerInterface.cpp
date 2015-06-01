#include "playerInterface.h"
#include "map\mapPosition.h"
#include "items\item.h"

using namespace game;
using namespace objects;
using namespace gamemap;
using namespace items;

CPlayerInterface::CPlayerInterface( creatures::ICreature::Ptr creature_, IUserInterface& ui_ )
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

      if ( objects.size() == 1 )
      {
         auto item = std::dynamic_pointer_cast<IItem>(*objects.begin());
         creature->carryItem( item );
      }
      else if ( objects.size() > 1 )
      {
         auto obj = ui.selectObject( objects );
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

      if ( items.size() != 1 )
      {
         auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
         auto map = mapPosition->getMap();
         const auto& coords = mapPosition->getCoords();

         map->place( *items.begin(), coords );
      }
      //else if ( items.size() > 1 ) // !!!
      //{
      //   auto obj = ui.selectObject( items );
      //   if ( obj )
      //   {
	     //    auto item = std::dynamic_pointer_cast<IItem>(obj);
	     //    creature->carryItem( item );
      //   }
      //}
   }
}

void game::CPlayerInterface::equipItem()
{
   auto position = creature->getPosition();
   if ( position && position->getPositionType() == TPositionType::map )
   {
      auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
      const auto& coords = mapPosition->getCoords();
      auto map = mapPosition->getMap();

      auto object = map->getObject( coords, TObjectType::item );
      if ( object )
      {
         auto item = std::dynamic_pointer_cast<IItem>( object );
         creature->equip( item );
      }
   }
}
