#include "selectWindow.h"
#include "consoleOperations.h"
#include "keys.h"

const int X1_ = 50;
const int X2_ = 79;
const int Y1_ = 0;
const int Y2_ = 23;

using namespace game_engine;

CSelectWindow::CSelectWindow( const NameableVector& nameableVector_ )
   : nameableVector( nameableVector_ )
   , current{ nameableVector.begin() }
{}

CSelectWindow::~CSelectWindow()
{
   clearRectangle( X1_, Y1_, X2_, Y2_ );
}

int CSelectWindow::eventHandler( int key )
{
   switch ( key )
   {
      case K_j:
         ++current;
         if ( current == nameableVector.end() )
            current = nameableVector.begin();

         redraw();
      break;

      case K_k:
         if ( current == nameableVector.begin() )
            current = nameableVector.end();
         --current;

         redraw();
      break;

      case k_enter:
         key = -key;
      break;
   }
   return key;
}

void CSelectWindow::redraw()
{
   clearRectangle( X1_, Y1_, X2_, Y2_ );

   int i = 0;
   for ( auto it = nameableVector.begin(); it != nameableVector.end(); ++it )
   {
      if ( it == current )
         SetColor( White, DarkGray );
      else
         SetColor( White, Black );

      gotoXY( X1_, i );
      printf( "%s", (*it)->getName().c_str() );

      i++;
   }
   SetColor( LightGray, Black );
}

INameable::Ptr CSelectWindow::getSelected()
{
   return *current;
}
