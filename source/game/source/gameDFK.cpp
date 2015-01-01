#include "gameDFK.h"
#include "map\h\objects.h"

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
   player = new CDwarf;
   addObject( player, 1, 1 );
   addObject( new CWeapon, 4, 2 );
   addObject( new CWeapon, 5, 7 );
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
         moveObject( player, player->getx() - 1, player->gety() );
      break;

      case K_j :
         moveObject( player, player->getx(), player->gety() + 1 );
      break;

      case K_k :
         moveObject( player, player->getx(), player->gety() - 1 );
      break;

      case K_l :
         moveObject( player, player->getx() + 1, player->gety() );
      break;
   }
   return key;
}

void CGameDFK::step()
{
}
