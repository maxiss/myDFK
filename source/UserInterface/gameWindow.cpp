#include "gameWindow.h"

#include "consoleWindow.h"
#include "consoleOperations.h"
#include "eventHandler.h"
#include "game\interface.h"
#include "objectTypeVisualizator.h"

#define K_SPACE 32

#define K_d 100
#define K_g 103
#define K_h 104
#define K_j 106
#define K_k 107
#define K_l 108

using namespace game;
using namespace gamemap;

class CGameWindow : public CConsoleWindow
{
public:
   CGameWindow( IGame::Ptr );
private:
   virtual int eventHandler( int key ) override final;
   void redraw();

   void draw( const TMapPointList& );
   void draw( const TMapPoint& );
   void redrawChanges();

   void drawChar( const TMapPoint& mapPoint );


private: // data
   IGame::Ptr game;
   IPlayerInterface::Ptr player;
   CMapPointVisuzlizator typeChars;
};

CGameWindow::CGameWindow( IGame::Ptr game_ )
   : game{ game_ }
   , player{ game->getPlayerInterface() }
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

      case 27:
         key = -key;
      break;

      case 999:
         redraw();
      break;

      default:
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

void CGameWindow::draw( const TMapPointList& changes )
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
      objects::IObject::ConstPtr object = *mapPoint.objectList.begin();
      printf( "%c", typeChars.getObjectTypeChar( object->getObjectType() ) );
   }
}

void runGameWindow()
{
   IGame::Ptr gameInstance = startGame();

   auto gameWindow = std::make_shared< CGameWindow >( gameInstance );
   CEventHandler::Instance().pushWindow( gameWindow );
}
