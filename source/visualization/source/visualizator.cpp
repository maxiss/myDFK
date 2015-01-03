#include "visualizator.h"
#include "game/h/threads.h"
#include <Windows.h>

using namespace visualization;
using namespace gamemap;

#define SLEEP_TIME 100

CVisualizator::CVisualizator( const CMap& map_ )
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
   const TMapPointList changes = map.getMapChanges();
   map.clearChanges();
   for ( TMapPointList::const_iterator it = changes.begin(); it != changes.end(); ++it )
   {
      draw( *it );
   }
}
