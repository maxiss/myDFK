#include "interface.h"

#include "ConsoleUI.h"

using namespace user_interface;

void startUI()
{
   CConsoleUI::Instance().start();
}
