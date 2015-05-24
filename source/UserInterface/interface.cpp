#include "interface.h"

#include "IUserInterface.h"
#include "ConsoleUI.h"

using namespace user_interface;

void startUI()
{
   auto ui = std::make_shared< CConsoleUI >();
   ui->start();
}
