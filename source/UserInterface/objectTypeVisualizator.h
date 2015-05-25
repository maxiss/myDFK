#pragma once

#include <map>
#include "objects\ObjectTypes.h"
#include "map\structure.h"

class CMapPointVisuzlizator
{
public:
   CMapPointVisuzlizator();
   char getObjectTypeChar( objects::TObjectType objType ) const;
   char getStructureTypeChar( gamemap::TStructureType structureType ) const;

private:
   std::map< objects::TObjectType, char > objectTypeList;
   std::map< gamemap::TStructureType, char > structureTypeList;

   void fillTypeObjectList();
   void fillStructureTypeList();
};
