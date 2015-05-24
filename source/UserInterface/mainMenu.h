#pragma once

#include "consoleWindow.h"

class CMainMenuWindow : public CConsoleWindow
{
public:
   CMainMenuWindow();

private:
   virtual int eventHandler( int key ) override final;
   void redraw();

};
