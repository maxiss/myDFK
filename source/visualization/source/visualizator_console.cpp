#include "visualizator.h"
#include <Windows.h>

using namespace visualization;
using namespace gamemap;

static void gotoXY( const int& xpos, const int& ypos )
{
   COORD scrn = { xpos, ypos };
   HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
   SetConsoleCursorPosition( hOuput, scrn );
}

void CVisualizator::initConsole()
{
   CONSOLE_CURSOR_INFO cInfo;
   HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
   GetConsoleCursorInfo( hOuput, &cInfo );
   cInfo.bVisible = false;
   SetConsoleCursorInfo( hOuput, &cInfo );
}

void CVisualizator::draw( const gamemap::TPosition& pos )
{
   gotoXY( pos.position.x, pos.position.y );
   draw( pos.objectType );
}

void CVisualizator::draw( const gamemap::TObjectType& objType )
{
   switch (objType)
   {
      case OBJ_TYPE_EMPTY :
         printf( "." );
      break;

      case OBJ_TYPE_ITEM :
         printf( "i" );
      break;

      case OBJ_TYPE_CREATURE :
         printf( "@" );
      break;

   }
}
