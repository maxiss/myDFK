#pragma once

#include "consoleWindow.h"

class CMainMenuWindow final
   : public CConsoleWindow
{
private:
   virtual int eventHandler( int key ) override final;
   virtual void redraw() override final;
};
