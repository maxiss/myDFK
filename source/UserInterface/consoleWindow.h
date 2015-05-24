#pragma once

#include <memory>
class CEventHandler;

class CConsoleWindow : private std::enable_shared_from_this< CConsoleWindow >
{
public:
   typedef std::shared_ptr< CConsoleWindow > Ptr;

private:
   friend CEventHandler;
   virtual int eventHandler( int key ) = 0;
};
