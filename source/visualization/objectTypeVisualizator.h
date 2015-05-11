#pragma once

#include <map>
#include "map\object.h"
#include "map\structure.h"

namespace visualization
{
   using namespace gamemap;

   typedef std::map< gamemap::TObjectType, char > TObjectTypeList;
   typedef std::map< gamemap::TStructureType, char > TStructureTypeList;

   class CMapPointVisuzlizator
   {
   public:
      CMapPointVisuzlizator();
      char getObjectTypeChar( const TObjectType& objType ) const;
      char getStructureTypeChar( const TStructureType& structureType ) const;

   private:
      TObjectTypeList objectTypeList;
      TStructureTypeList structureTypeList;

      void fillTypeObjectList();
      void fillStructureTypeList();

   };

}
