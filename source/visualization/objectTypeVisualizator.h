#pragma once

#include <map>
#include "objects\ObjectTypes.h"
#include "map\structure.h"

namespace visualization
{
   using namespace gamemap;

   typedef std::map< objects::TObjectType, char > TObjectTypeList;
   typedef std::map< gamemap::TStructureType, char > TStructureTypeList;

   class CMapPointVisuzlizator
   {
   public:
      CMapPointVisuzlizator();
      char getObjectTypeChar( objects::TObjectType objType ) const;
      char getStructureTypeChar( TStructureType structureType ) const;

   private:
      TObjectTypeList objectTypeList;
      TStructureTypeList structureTypeList;

      void fillTypeObjectList();
      void fillStructureTypeList();

   };

}
