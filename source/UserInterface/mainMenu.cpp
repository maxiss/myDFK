#include "mainMenu.h"

#include "consoleOperations.h"

CMainMenuWindow::CMainMenuWindow()
{
   gotoXY( 30, 10 ); // !!! consts
   printf( "%s", "Start game <Enter>" );
   gotoXY( 34, 13 ); // !!! consts
   printf( "%s", "Exit <Esc>" );
}

int CMainMenuWindow::eventHandler( int key )
{
   switch ( key )
   {
      case 13:
         // !!! startGame
      break;

      case 27:
         key = -key;
      break;

      default:
      break;
   }

   return key;
}
