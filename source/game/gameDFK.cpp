#include "gameDFK.h"
#include "playerInterface.h"
#include "items\weapon.h"
#include "items\backpack.h"

using namespace game_engine;

void CGameDFK::initData()
{
   player.reset( new CDwarf );
   addObjectToMap( player, 1, 1 );
   addObjectToMap( std::make_shared< CWeapon >(), 4, 2 );
   addObjectToMap( std::make_shared< CWeapon >(), 5, 7 );
   addObjectToMap( std::make_shared< CBackPack >(), 8, 4 );
}

IPlayerInterface::Ptr CGameDFK::getPlayerInterface( IUserInterface& ui )  
{
   return std::make_shared< CPlayerInterface >( player, ui );
}
