#include "visualizator_console.h"
#include <Windows.h>

using namespace visualization;
using namespace gamemap;

static void gotoXY( const int& xpos, const int& ypos )
{
   COORD scrn = { xpos, ypos };
   HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
   SetConsoleCursorPosition( hOuput, scrn );
}

CVisualizator_console::CVisualizator_console( const CMap& gamemap )
   : CVisualizator( gamemap )
{
   initConsole();
}

void CVisualizator_console::initConsole()
{
   CONSOLE_CURSOR_INFO cInfo;
   HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
   GetConsoleCursorInfo( hOuput, &cInfo );
   cInfo.bVisible = false;
   SetConsoleCursorInfo( hOuput, &cInfo );
}

void CVisualizator_console::draw( const TMapPoint& mapPoint )
{
   gotoXY( mapPoint.point.x, mapPoint.point.y );
   draw( mapPoint.mapPoint );
}

void CVisualizator_console::draw( const CMapPoint& mapPoint )
{
   if ( mapPoint.isEmpty() )
      printf( typeChars.getStructureTypeChar( mapPoint.structure.type ) );
   else
      printf( typeChars.getObjectTypeChar( mapPoint.get()->getObjectType() ) );
}
