#pragma once

#include "visualizator.h"
#include "objectTypeVisualizator.h"

namespace visualization
{
   using namespace gamemap;

   class CVisualizator_console : public CVisualizator
   {
   public:
      CVisualizator_console( const CMap& gamemap );

   private:
      CTypeObjectVisualizator objTypeChars;
      virtual void draw( const TMapPoint& mapPoint );
      void initConsole();
      void draw( const CMapPoint& mapPoint );

   };

}
