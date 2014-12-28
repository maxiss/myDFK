#include "visualizator.h"
#include "game/h/threads.h"
#include <Windows.h>

using namespace visualization;
using namespace gamemap;

#define SLEEP_TIME 100

CVisualizator::CVisualizator( const gamemap::CMap& map_ )
   : map(map_)
{
}

void CVisualizator::gameLoop()
{
   loop = true;
   while (loop)
   {
      frame();
      Sleep( SLEEP_TIME );
   }
}

void CVisualizator::stop()
{
   loop = false;
}

void CVisualizator::frame()
{
   const TPositionList posList = map.getMapPositionList();
   for ( TPositionList::const_iterator pos = posList.begin(); pos != posList.end(); ++pos )
   {
      draw( *pos );
   }
}
