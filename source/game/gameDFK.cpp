#include "gameDFK.h"
#include "items\weapon.h"
#include "player.h"

using namespace game;
using namespace creatures;
using namespace items;

void CGameDFK::initData()
{
   player.reset( new CDwarf );
   addObjectToMap( player, 1, 1 );
   addObjectToMap( std::make_shared< CWeapon >(), 4, 2 );
   addObjectToMap( std::make_shared< CWeapon >(), 5, 7 );
}
