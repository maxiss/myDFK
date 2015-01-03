#pragma once

#include <map>
#include "map\h\object.h"
#include "map\h\structure.h"

namespace visualization
{
   using namespace gamemap;

   typedef std::map< gamemap::TObjectType, const char* > TObjectTypeList;
   typedef std::map< gamemap::TStructureType, const char* > TStructureTypeList;

   class CMapPointVisuzlizator
   {
   public:
      CMapPointVisuzlizator();
      const char* getObjectTypeChar( const TObjectType& objType ) const;
      const char* getStructureTypeChar( const TStructureType& structureType ) const;

   private:
      TObjectTypeList objectTypeList;
      TStructureTypeList structureTypeList;

      void fillTypeObjectList();
      void fillStructureTypeList();

   };

}
