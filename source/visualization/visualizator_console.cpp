#include "visualizator_console.h"
#include <Windows.h>
#include "game\gameInstance.h"

using namespace visualization;
using namespace gamemap;

//static void gotoXY( const int& xpos, const int& ypos )
//{
//   COORD scrn = { xpos, ypos };
//   HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
//   SetConsoleCursorPosition( hOuput, scrn );
//}

CVisualizator_console::CVisualizator_console( CMap::ConstPtr map_ )
   : CVisualizator( map_ )
{
   //initConsole();
}

void CVisualizator_console::initConsole()
{
   //CONSOLE_CURSOR_INFO cInfo;
   //HANDLE hOuput = GetStdHandle( STD_OUTPUT_HANDLE );
   //GetConsoleCursorInfo( hOuput, &cInfo );
   //cInfo.bVisible = false;
   //SetConsoleCursorInfo( hOuput, &cInfo );
}

void CVisualizator_console::draw( const TMapPoint& mapPoint )
{
   //gotoXY( mapPoint.coords.x, mapPoint.coords.y );
   //drawChar( mapPoint );
}

void CVisualizator_console::drawChar( const TMapPoint& mapPoint )
{
   //if ( mapPoint.objectList.empty() )
   //   printf( "%c", typeChars.getStructureTypeChar( mapPoint.structureType ) );
   //else
   //{
   //   objects::IObject::ConstPtr object = *mapPoint.objectList.begin();
   //   printf( "%c", typeChars.getObjectTypeChar( object->getObjectType() ) );
   //}
}

const int X_LAYOUT = 50;

void visualization::CVisualizator_console::drawPlayerInterface() // !!! need refactoring
{
   //for ( int i = 0; i < 10; i++ )
   //{
   //   gotoXY( X_LAYOUT-1, i );
   //   printf( "%s", "                    " );
   //}

   //auto& playerInterface = game::getGame()->getPlayerInterface();
   //if ( playerInterface->isNeedSelect() )
   //{
   //   const auto& list = playerInterface->getFullList();
   //   int i = 0;
   //   for ( auto it : list )
   //   {
   //      gotoXY( X_LAYOUT, i );
   //      printf( "%s", "test" );
   //      i++;
   //   }

   //   gotoXY( X_LAYOUT - 1, playerInterface->getIndex() );
   //   printf( "%c", 'x' );
   //}
}
