#include "selectWindow.h"
#include "consoleOperations.h"
#include "keys.h"

const int X1_ = 50;
const int X2_ = 79;
const int Y1_ = 0;
const int Y2_ = 23;

using namespace objects;

CSelectWindow::CSelectWindow( const TObjectList& objectList_ )
   : objectList( objectList_ )
   , current{ objectList.begin() }
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
         if ( current == objectList.end() )
            current = objectList.begin();

         redraw();
      break;

      case K_k:
         if ( current == objectList.begin() )
            current = objectList.end();
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
   for ( auto it = objectList.begin(); it != objectList.end(); ++it )
   {
      if ( it == current )
         SetColor( White, DarkGray );
      else
         SetColor( White, Black );

      gotoXY( X1_, i );
      printf( "testing" );

      i++;
   }
   SetColor( White, Black );
}

objects::IObject::Ptr CSelectWindow::getSelected()
{
   return *current;
}
