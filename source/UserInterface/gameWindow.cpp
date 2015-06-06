#include "gameWindow.h"

#include "consoleWindow.h"
#include "consoleOperations.h"
#include "game\interface.h"
#include "objectTypeVisualizator.h"
#include "ConsoleUI.h"
#include "keys.h"

using namespace game_engine;
using namespace user_interface;

class CGameWindow : public CConsoleWindow
{
public:
   CGameWindow( IGame::Ptr );
private:
   virtual int eventHandler( int key ) override final;
   virtual void redraw() override final;

   void draw( const MapPointList& );
   void draw( const TMapPoint& );
   void redrawChanges();

   void drawChar( const TMapPoint& mapPoint );


private: // data
   IGame::Ptr game;
   IPlayerInterface::Ptr player;
   CMapPointVisuazlizator typeChars;
};

CGameWindow::CGameWindow( IGame::Ptr game_ )
   : game{ game_ }
   , player{ game->getPlayerInterface( CConsoleUI::Instance() ) }
{}

// TODO: bare out key mapping to other class
int CGameWindow::eventHandler( int key )
{
   switch ( key )
   {
      case K_d :
         player->dropItem();
         redrawChanges();
      break;

      case K_e :
         player->equipItem();
         redrawChanges();
      break;

      case K_g :
         player->pickUpItem();
         redrawChanges();
      break;

      case K_h :
         player->moveLeft();
         redrawChanges();
      break;

      case K_j :
         player->moveDown();
         redrawChanges();
      break;

      case K_k :
         player->moveUp();
         redrawChanges();
      break;

      case K_l :
         player->moveRight();
         redrawChanges();
      break;

      case K_t :
         player->takeOffItem();
         redrawChanges();
      break;
   }

   return key;
}

void CGameWindow::redraw()
{
   system( "cls" );
   hideConsoleCursor();

   auto map = game->getMap();
   draw( map->getMapPositionList() );
}

void CGameWindow::draw( const MapPointList& changes )
{
   for ( const auto& it : changes )
      draw( it );
}

void CGameWindow::draw( const TMapPoint& mapPoint )
{
   gotoXY( mapPoint.coords.x, mapPoint.coords.y );
   drawChar( mapPoint );
}

void CGameWindow::redrawChanges()
{
   auto map = game->getMap();
   draw( map->getMapChanges() );
}

void CGameWindow::drawChar( const TMapPoint& mapPoint )
{
   if ( mapPoint.objectList.empty() )
      printf( "%c", typeChars.getStructureTypeChar( mapPoint.structureType ) );
   else
   {
      IObject::ConstPtr object = *mapPoint.objectList.begin();
      printf( "%c", typeChars.getObjectTypeChar( object->getObjectType() ) );
   }
}

void runGameWindow()
{
   IGame::Ptr gameInstance = startGame();
   CGameWindow( gameInstance ).run();
}
