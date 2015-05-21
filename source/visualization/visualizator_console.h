#pragma once

#include "visualizator.h"
#include "objectTypeVisualizator.h"

namespace visualization
{
   class CVisualizator_console : public CVisualizator
   {
   public:
      CVisualizator_console( gamemap::CMap::ConstPtr );

   private:
      CMapPointVisuzlizator typeChars;
      virtual void draw( const gamemap::TMapPoint& mapPoint ) override final;
      virtual void drawPlayerInterface() override final;
      void initConsole();
      void drawChar( const gamemap::TMapPoint& mapPoint );

   };

}
