#include "consoleWindow.h"
#include <conio.h>
#include "keys.h"

int CConsoleWindow::run()
{
   redraw();
   return _eventHandler();
}

int CConsoleWindow::_eventHandler()
{
   int key = 0;
   while ( key >= 0 )
   {
      key = _getch();
      key = eventHandler( key );

      if ( key == k_esc )
         key = -key;
   }
   return -key;
}
