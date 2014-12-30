#include "gameDFK.h"
#include "map\h\objects.h"

using namespace game;
using namespace gamemap;

#define K_SPACE 32

void CGameDFK::initData()
{
   addObject( new creatures::CDwarf, TPoint( 1, 1 ) );
   addObject( new items::CWeapon, TPoint( 4, 2 ) );
   addObject( new items::CWeapon, TPoint( 5, 7 ) );
}

// TODO: bare out key mapping to other class
int CGameDFK::eventHandler( int key )
{
   switch (key)
   {
      case K_SPACE :
         map.addObject( new items::CWeapon, gamemap::TPoint( 5, 5 ) ); 
      break;

   }
   return key;
}

void CGameDFK::step()
{
}

CObject* CGameDFK::addObject( CObject* object )
{
   objects.push_back( object );
   return object;
}

CObject* CGameDFK::addObject( CObject* object, TPoint point )
{
   addObject( object );
   map.addObject( object, point );
   return object;
}
