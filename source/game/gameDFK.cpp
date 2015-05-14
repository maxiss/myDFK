#include "gameDFK.h"
#include "map\objects.h"
#include "items\weapon.h"

using namespace game;
using namespace gamemap;
using namespace creatures;
using namespace items;

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
   addObject( player, 1, 1 );
   addObject( std::make_shared< CWeapon >(), 4, 2 );
   addObject( std::make_shared< CWeapon >(), 5, 7 );
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
         creatureCarryItem( player );
      break;

      case K_h :
      {
         TCoords coords = player->getCoords();
         moveObject( player, coords.x - 1, coords.y );
      }
      break;

      case K_j :
      {
         TCoords coords = player->getCoords();
         moveObject( player, coords.x, coords.y + 1 );
      }
      break;

      case K_k :
      {
         TCoords coords = player->getCoords();
         moveObject( player, coords.x, coords.y - 1 );
      }
      break;

      case K_l :
      {
         TCoords coords = player->getCoords();
         moveObject( player, coords.x + 1, coords.y );
      }
      break;
   }
   return key;
}

void CGameDFK::step()
{
}
