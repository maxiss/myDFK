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

void CVisualizator::start()
{
   threads::CThread <CVisualizator> visualLoop( *this, &visualization::CVisualizator::loop );
}

void CVisualizator::loop()
{
   while (true)
   {
      frame();
      Sleep( SLEEP_TIME );
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
