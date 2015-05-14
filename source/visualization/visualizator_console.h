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
      CMapPointVisuzlizator typeChars;
      virtual void draw( const TMapPoint& mapPoint ) override final;
      void initConsole();
      void drawChar( const TMapPoint& mapPoint );

   };

}
