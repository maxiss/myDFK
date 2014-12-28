#pragma once

#include "visualizator.h"
#include "objectTypeVisualizator.h"

namespace visualization
{
   class CVisualizator_console : public CVisualizator
   {
   public:
      CVisualizator_console( const gamemap::CMap& gamemap );

   private:
      CTypeObjectVisualizator objTypeChars;
      virtual void draw( const gamemap::TPosition& pos );
      void initConsole();
      void draw( const gamemap::TObjectType& objType );

   };

}
