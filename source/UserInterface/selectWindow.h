#pragma once

#include "consoleWindow.h"
#include "objects\IObject.h"

class CSelectWindow
   : public CConsoleWindow
{
public:
   CSelectWindow( const objects::TObjectList& );
   ~CSelectWindow();
   objects::IObject::Ptr getSelected();

private:
   virtual int eventHandler( int key ) override final;
   virtual void redraw() override final;

private: // data
   objects::TObjectList objectList;
   objects::TObjectList::iterator current;
};
