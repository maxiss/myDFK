#include "visualizator.h"
#include <iostream>

using namespace visualization;
using namespace std;

CVisualizator::CVisualizator()
 : test( 0 )
{
}


void CVisualizator::start()
{
   cout << "Hello, world!" << endl;
}

int CVisualizator::loop()
{
   cout << "test" << test++ << endl;
   return 0;
}
