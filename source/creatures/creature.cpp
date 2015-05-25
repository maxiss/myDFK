#include "creature.h"
#include "items\containerPosition.h"
#include "items\backpack.h"
#include "map\mapPosition.h"
#include "game\gameInstance.h"

using namespace creatures;
using namespace items;
using namespace objects;
using namespace gamemap;
using namespace game;

objects::TObjectType ICreature::getObjectType() const
{
   return objects::TObjectType::creature;
}

IItem::Ptr ICreature::getItem()
{
   if ( storage )
      return storage->get();
   else
      return nullptr;
}

void ICreature::carryItem( IItem::Ptr item )
{
   if ( storage )
      storage->store( item );
}

void ICreature::pickUpItem()
{
   if ( position && position->getPositionType() == TPositionType::map  )
   {
      auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
      const auto& coords = mapPosition->getCoords();
      auto map = mapPosition->getMap();

      auto objects = map->getObjects( coords, TObjectType::item );

      if ( objects.size() == 1 )
      {
         auto item = std::dynamic_pointer_cast<IItem>(*objects.begin());
         carryItem( item );
      }
      else if ( objects.size() > 1 )
      {
         //auto obj = getGame()->getPlayerInterface()->selectObject( objects );
         //if ( obj )
         //{
	        // auto item = std::dynamic_pointer_cast<IItem>(obj);
	        // carryItem( item );
         //}
      }
   }
}

void ICreature::move( coord dx, coord dy )
{
   if ( position && position->getPositionType() == TPositionType::map  )
   {
      auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
      auto coords = mapPosition->getCoords();
      coords.x += dx;
      coords.y += dy;
      mapPosition->setCoords( coords );
   }
}

void ICreature::dropItem()
{
   if ( position && position->getPositionType() == TPositionType::map  )
   {
      auto item = getItem();
      if ( item )
      {
         auto mapPosition = std::dynamic_pointer_cast<CMapPosition>( position );
         auto map = mapPosition->getMap();
         const auto& coords = mapPosition->getCoords();

         item->setPosition( std::make_shared<CMapPosition>( item, map, coords ) );
      }
   }
}
