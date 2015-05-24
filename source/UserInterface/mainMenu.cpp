#include "mainMenu.h"

#include "consoleOperations.h"
#include "gameWindow.h"

CMainMenuWindow::CMainMenuWindow()
{}

int CMainMenuWindow::eventHandler( int key )
{
   switch ( key )
   {
      case 13:
      {
         runGameWindow();
      }
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

void CMainMenuWindow::redraw()
{
   system( "cls" );
   hideConsoleCursor();
   gotoXY( 30, 10 ); // !!! consts
   printf( "%s", "Start game <Enter>" );
   gotoXY( 34, 13 ); // !!! consts
   printf( "%s", "Exit <Esc>" );
}
