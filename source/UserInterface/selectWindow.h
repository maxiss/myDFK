#pragma once

#include "consoleWindow.h"
#include "objects/INameable.h"

class CSelectWindow
   : public CConsoleWindow
{
public:
   CSelectWindow( const game_engine::NameableVector& );
   ~CSelectWindow();
   game_engine::INameable::Ptr getSelected();

private:
   virtual int eventHandler( int key ) override final;
   virtual void redraw() override final;

private: // data
   game_engine::NameableVector nameableVector;
   game_engine::NameableVector::iterator current;
};
