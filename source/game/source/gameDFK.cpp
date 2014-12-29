#include "gameDFK.h"
#include "map\h\objects.h"

using namespace game;

void CGameDFK::initData()
{
   map.addObject( new creatures::CDwarf, gamemap::TPoint( 1, 1 ) ); 
   map.addObject( new items::CWeapon, gamemap::TPoint( 4, 2 ) ); 
   map.addObject( new items::CWeapon, gamemap::TPoint( 5, 7 ) ); 
}

// TODO: bare out key mapping to other class
int CGameDFK::eventHandler( int key )
{
   switch (key)
   {
      case 32 :
         map.addObject( new items::CWeapon, gamemap::TPoint( 5, 5 ) ); 
      break;

   }
   return key;
}

void CGameDFK::step()
{
}
