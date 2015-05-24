#include "ConsoleUI.h"

#include <Windows.h>
#include <conio.h>
#include "eventHandler.h"
#include "mainMenu.h"

using namespace user_interface;

void CConsoleUI::start()
{
   auto menu = std::make_shared< CMainMenuWindow >();
   CEventHandler::Instance().pushWindow( menu );
   CEventHandler::Instance().start();
}
