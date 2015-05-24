#pragma once

#include <stack>
#include <conio.h>
#include "consoleWindow.h"

class CEventHandler
{
public:
   static CEventHandler& Instance()
   {
      static CEventHandler instance;
      return instance;
   }
   
   void start()
   {
      while ( !windowStack.empty() )
      {
         int key = _getch();
         key = windowStack.top()->eventHandler( key );
         if ( key < 0 )
         {
            windowStack.pop();
            if ( !windowStack.empty() )
               windowStack.top()->eventHandler( 999 ); // !!!
         }
      }
   }

   void pushWindow( CConsoleWindow::Ptr window )
   {
      windowStack.push( window );
      windowStack.top()->eventHandler( 999 ); // !!!
   }

   void popWindow()
   {
      windowStack.pop();
   }

private:
   CEventHandler() {}
   std::stack< CConsoleWindow::Ptr > windowStack;

};
