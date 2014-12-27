#include "visualizator.h"
#include <iostream>

using namespace visualization;
using namespace std;
using namespace gamemap;

CVisualizator::CVisualizator( const gamemap::CMap& map_ )
   : map(map_)
{
}

void CVisualizator::loop()
{
   const TPositionList posList = map.getMapPositionList();
   //for ( TPositionList::const_iterator pos = posList.begin(); pos != posList.end(); ++pos )
   //{
   //}

   // !!!
   TPositionList::const_iterator pos = posList.begin();
   if (pos->objectType == OBJ_TYPE_EMPTY)
      cout << "." << endl;
   else
      cout << "?" << endl;
}
