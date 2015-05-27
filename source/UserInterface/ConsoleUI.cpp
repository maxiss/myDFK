#include "ConsoleUI.h"

#include "mainMenu.h"
#include "selectWindow.h"
#include "keys.h"

using namespace user_interface;
using namespace objects;

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

IObject::Ptr CConsoleUI::selectObject( const TObjectList& objectList )
{
   IObject::Ptr retVal = nullptr;

   CSelectWindow selectWindow( objectList );
   int key = selectWindow.run();
   if ( key == k_enter )
      retVal = selectWindow.getSelected();

   return retVal;
}
