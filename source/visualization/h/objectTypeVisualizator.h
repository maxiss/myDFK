#pragma once

#include <map>
#include "map\h\object.h"

namespace visualization
{
   typedef std::map< gamemap::TObjectType, const char* > TTypeObjectList;

   class CTypeObjectVisualizator
   {
   public:
      CTypeObjectVisualizator();
      const char* getTypeObjectChar( const gamemap::TObjectType& objType ) const;

   private:
      TTypeObjectList typeObjectList;

   };

}
