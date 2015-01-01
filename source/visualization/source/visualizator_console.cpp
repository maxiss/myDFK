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

void CVisualizator_console::draw( const TPosition& pos )
{
   gotoXY( pos.position.x, pos.position.y );
   draw( pos.objectType );
}

void CVisualizator_console::draw( const TObjectType& objType )
{
   printf( objTypeChars.getTypeObjectChar( objType ) );
}
