#pragma once

#include <map>
#include "objects\ObjectTypes.h"
#include "map\structure.h"

namespace visualization
{
   typedef std::map< objects::TObjectType, char > TObjectTypeList;
   typedef std::map< gamemap::TStructureType, char > TStructureTypeList;

   class CMapPointVisuzlizator
   {
   public:
      CMapPointVisuzlizator();
      char getObjectTypeChar( objects::TObjectType objType ) const;
      char getStructureTypeChar( gamemap::TStructureType structureType ) const;

   private:
      TObjectTypeList objectTypeList;
      TStructureTypeList structureTypeList;

      void fillTypeObjectList();
      void fillStructureTypeList();

   };

}
