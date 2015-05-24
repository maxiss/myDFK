#include "gameWindow.h"

#include "consoleWindow.h"
#include "consoleOperations.h"
#include "eventHandler.h"
#include "game\interface.h"

using namespace game;

class CGameWindow : public CConsoleWindow
{
public:
   CGameWindow( CGame::Ptr );
private:
   virtual int eventHandler( int key ) override final;
   void redraw();
   void redrawChanges();

private: // data
   CGame::Ptr game;
};

CGameWindow::CGameWindow( CGame::Ptr game_ )
   : game( game_ )
{}

int CGameWindow::eventHandler( int key )
{
   switch ( key )
   {
      case 27:
         key = -key;
      break;

      case 32:
         redrawChanges();
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
   gotoXY( 0, 0 );
   printf( "%s", "GameGameGame..." );
}

void CGameWindow::redrawChanges()
{
   throw std::logic_error( "The method or operation is not implemented." );
}

void runGameWindow()
{
   CGame::Ptr gameInstance = startGame();
   // gameInstance.createPlayerInterface;

   auto gameWindow = std::make_shared< CGameWindow >( gameInstance );
   CEventHandler::Instance().pushWindow( gameWindow );
}
