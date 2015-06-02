#pragma once

#include "consoleWindow.h"
#include "objects/INameable.h"

class CSelectWindow
   : public CConsoleWindow
{
public:
   CSelectWindow( const objects::TNameableVector& );
   ~CSelectWindow();
   objects::INameable::Ptr getSelected();

private:
   virtual int eventHandler( int key ) override final;
   virtual void redraw() override final;

private: // data
   objects::TNameableVector nameableVector;
   objects::TNameableVector::iterator current;
};
