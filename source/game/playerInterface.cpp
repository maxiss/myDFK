#include "playerInterface.h"
#include <conio.h>
#include "map\mapPosition.h"
#include "items\item.h"

#define K_d 100
#define K_g 103
#define K_h 104
#define K_j 106
#define K_k 107
#define K_l 108
#define K_Enter 13

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
      auto item = creature->getItem();
      if ( item )
      {
         auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
         auto map = mapPosition->getMap();
         const auto& coords = mapPosition->getCoords();

         item->setPosition( std::make_shared<CMapPosition>( item, map, coords ) );
      }
   }
}
