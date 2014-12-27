#include "visualizator.h"
#include <Windows.h>

using namespace visualization;
using namespace gamemap;

CVisualizator::CVisualizator( const gamemap::CMap& map_ )
   : map(map_)
{
   initConsole();
}

void CVisualizator::loop()
{
   while (true)
   {
      frame();
      Sleep( 100 );
   }
}

void CVisualizator::frame()
{
   const TPositionList posList = map.getMapPositionList();
   for ( TPositionList::const_iterator pos = posList.begin(); pos != posList.end(); ++pos )
   {
      draw( *pos );
   }
}
