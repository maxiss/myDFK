#include "selectWindow.h"
#include "consoleOperations.h"

#define K_d 100
#define K_g 103
#define K_h 104
#define K_j 106
#define K_k 107
#define K_l 108

const int X1 = 50;
const int X2 = 79;
const int Y1 = 0;
const int Y2 = 23;

using namespace objects;

CSelectWindow::CSelectWindow( const TObjectList& objectList_ )
   : objectList( objectList_ )
   , current{ objectList.begin() }
{}

CSelectWindow::~CSelectWindow()
{
   clearRectangle( X1, Y1, X2, Y2 );
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

      case 13:
         key = -key;
      break;
   }
   return key;
}

void CSelectWindow::redraw()
{
   clearRectangle( X1, Y1, X2, Y2 );

   int i = 0;
   for ( auto it = objectList.begin(); it != objectList.end(); ++it )
   {
      if ( it == current )
      {
         gotoXY( X1, i );
         printf( "*" );
      }
      gotoXY( X1 + 1, i );
      printf( "testing" );

      i++;
   }
}

objects::IObject::Ptr CSelectWindow::getSelected()
{
   return *current;
}
