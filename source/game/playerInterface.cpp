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

game::CPlayerInterface::CPlayerInterface( creatures::ICreature::Ptr creature_/*, CGame::Ptr game_*/ )
   : creature( creature_ )
   //, game( game_ )
{}

void game::CPlayerInterface::moveUp()
{
   creature->move( +0, -1 );
}

void game::CPlayerInterface::moveDown()
{
   creature->move( +0, +1 );
}

void game::CPlayerInterface::moveLeft()
{
   creature->move( -1, +0 );
}

void game::CPlayerInterface::moveRight()
{
   creature->move( +1, +0 );
}

void game::CPlayerInterface::pickUpItem()
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
         auto item = std::dynamic_pointer_cast<IItem>(*objects.begin());
         creature->carryItem( item );
      }
      //else if ( objects.size() > 1 )
      //{
      //   auto obj = getGame()->getPlayerInterface()->selectObject( objects );
      //   if ( obj )
      //   {
	     //    auto item = std::dynamic_pointer_cast<IItem>(obj);
	     //    carryItem( item );
      //   }
      //}
   }

}

void game::CPlayerInterface::dropItem()
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

//int CPlayer::eventHandler( int key )
//{
//   switch ( key )
//   {
//      case K_j:
//         ++listIterator;
//         ++index;
//         if ( listIterator == list.end() )
//         {
//            listIterator = list.begin();
//            index = 0;
//         }
//      break;
//
//      case K_k:
//         if ( listIterator == list.begin() )
//         {
//            listIterator = list.end();
//            index = list.size() - 1;
//         }
//         --listIterator;
//         --index;
//      break;
//
//      case K_Enter:
//         key = -key;
//      break;
//
//      default:
//         // do nothing
//      break;
//   }
//
//   return key;
//}

//IObject::Ptr CPlayer::selectObject( TObjectList& list_ )
//{
//   list = std::move( list_ );
//   listIterator = list.begin();
//   index = 0;
//   needSelect = true;
//
//   int key = 0;
//   while ( key >= 0 )
//   {
//      key = _getch(); // TODO: process 0-key
//      key = eventHandler( key );
//
//      if ( key == 27 )
//         key = -key;
//   }
//   key = -key;
//
//   IObject::Ptr retVal{ nullptr };
//   if ( key == K_Enter )
//      retVal = *listIterator;
//
//   list_ = std::move( list );
//   needSelect = false;
//   return retVal;
//}
//
//int game::CPlayer::getIndex()
//{
//   return index;
//}
//
//objects::IObject::ConstPtr game::CPlayer::getObject()
//{
//   return *listIterator;
//}
//
//const objects::TObjectList& game::CPlayer::getFullList()
//{
//   return list;
//}
//
//game::CPlayer::CPlayer()
//   : needSelect{ false }
//{}
//
//bool game::CPlayer::isNeedSelect()
//{
//   return needSelect;
//}

