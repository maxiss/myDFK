#pragma once

#include <map>
#include "map\h\object.h"

namespace visualization
{
   using namespace gamemap;

   typedef std::map< gamemap::TObjectType, const char* > TTypeObjectList;

   class CTypeObjectVisualizator
   {
   public:
      CTypeObjectVisualizator();
      const char* getTypeObjectChar( const TObjectType& objType ) const;

   private:
      TTypeObjectList typeObjectList;

   };

}
