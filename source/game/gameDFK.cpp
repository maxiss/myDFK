#include "gameDFK.h"
#include "map\objects.h"
#include "items\weapon.h"
#include "map\mapPosition.h"
#include "map\mapInstance.h"

using namespace game;
using namespace gamemap;
using namespace creatures;
using namespace items;
using namespace objects;

#define K_SPACE 32

#define K_d 100
#define K_g 103
#define K_h 104
#define K_j 106
#define K_k 107
#define K_l 108

void CGameDFK::initData()
{
   player.reset( new CDwarf );
   addObjectToMap( player, 1, 1 );
   addObjectToMap( std::make_shared< CWeapon >(), 4, 2 );
   addObjectToMap( std::make_shared< CWeapon >(), 5, 7 );
}

static void moveObject( IObject::Ptr object, int dx, int dy )
{
   IPositionBehavior::Ptr position = object->getPosition();
   if ( position->getPositionType() == TPositionType::map )
   {
      auto mapPosition = dynamic_cast<CMapPosition*>( position.get() );
      TCoords coords = mapPosition->getCoords();
      coords.x += dx;
      coords.y += dy;
      mapPosition->setCoords( coords );
   }
}

static void creaturePickUpItem( ICreature::Ptr creature )
{
   IPositionBehavior::Ptr position = creature->getPosition();
   if ( position.use_count() != 0 && position->getPositionType() == TPositionType::map )
   {
      auto mapPosition = dynamic_cast<CMapPosition*>( position.get() );
      const TCoords& coords = mapPosition->getCoords();
      CMap& map = Map::Intance().getMap();

      auto obj = map.getObject( coords, TObjectType::item );
      if ( obj.use_count() != 0 )
         creature->carryItem( std::dynamic_pointer_cast< IItem >( obj ) );
   }
}

static void creatureDropItem( ICreature::Ptr creature )
{
   IPositionBehavior::Ptr position = creature->getPosition();
   if ( position.use_count() != 0 && position->getPositionType() == TPositionType::map )
   {
      auto mapPosition = dynamic_cast<CMapPosition*>(position.get());
      const TCoords& coords = mapPosition->getCoords();

      IItem::Ptr item = creature->getItem();
      if ( item.use_count() != 0 )
      {
         creature->dropItem( item );
         item->setPosition( std::make_shared<CMapPosition>( item, coords ) );
      }
   }
}

// TODO: bare out key mapping to other class
int CGameDFK::eventHandler( int key )
{
   switch (key)
   {
      case K_d :
         creatureDropItem( player );
      break;

      case K_g :
         creaturePickUpItem( player );
      break;

      case K_h :
         moveObject( player, -1, +0 );
      break;

      case K_j :
         moveObject( player, +0, +1 );
      break;

      case K_k :
         moveObject( player, +0, -1 );
      break;

      case K_l :
         moveObject( player, +1, +0 );
      break;
   }
   return key;
}

void CGameDFK::step()
{
}
