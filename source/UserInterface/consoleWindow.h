#pragma once

#include <memory>
#include "IConsoleWindow.h"

class CConsoleWindow
   : virtual public IConsoleWindow
{
public:
   int run();
   int _eventHandler();

private:
   virtual int eventHandler( int key ) = 0;
   virtual void redraw() = 0;
};
