#include "ConsoleUI.h"

#include "mainMenu.h"
#include "selectWindow.h"
#include "keys.h"

using namespace user_interface;
using namespace game_engine;

CConsoleUI::CConsoleUI()
{}

CConsoleUI& CConsoleUI::Instance()
{
   static CConsoleUI instance;
   return instance;
}

void CConsoleUI::start()
{
   CMainMenuWindow().run();
}

INameable::Ptr CConsoleUI::select( const TNameableVector& nameableVector )
{
   INameable::Ptr retVal = nullptr;

   CSelectWindow selectWindow( nameableVector );
   int key = selectWindow.run();
   if ( key == k_enter )
      retVal = selectWindow.getSelected();

   return retVal;
}
