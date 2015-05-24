#include "gameDFK.h"
#include "items\weapon.h"
#include "player.h"

using namespace game;
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
   addObjectToMap( player, 1, 1 );
   addObjectToMap( std::make_shared< CWeapon >(), 4, 2 );
   addObjectToMap( std::make_shared< CWeapon >(), 5, 7 );
}

// TODO: bare out key mapping to other class
int CGameDFK::eventHandler( int key )
{
   switch (key)
   {
      case K_d :
         player->dropItem();
      break;

      case K_g :
         player->pickUpItem();
      break;

      case K_h :
         player->move( -1, +0 );
      break;

      case K_j :
         player->move( +0, +1 );
      break;

      case K_k :
         player->move( +0, -1 );
      break;

      case K_l :
         player->move( +1, +0 );
      break;
   }
   return key;
}

void CGameDFK::step()
{}

CGameDFK::CGameDFK()
{
   //playerInterface.reset( new CPlayer );
}
