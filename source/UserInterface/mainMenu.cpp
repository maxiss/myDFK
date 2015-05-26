#include "mainMenu.h"

#include "consoleOperations.h"
#include "gameWindow.h"

int CMainMenuWindow::eventHandler( int key )
{
   switch ( key )
   {
      case 13:
         runGameWindow();
         key = 0;
         redraw();
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
