#pragma once

#include <map>
#include "objects\ObjectTypes.h"
#include "map\structure.h"

class CMapPointVisuzlizator
{
public:
   CMapPointVisuzlizator();
   char getObjectTypeChar( game_engine::TObjectType objType ) const;
   char getStructureTypeChar( game_engine::TStructureType structureType ) const;

private:
   std::map< game_engine::TObjectType, char > objectTypeList;
   std::map< game_engine::TStructureType, char > structureTypeList;

   void fillTypeObjectList();
   void fillStructureTypeList();
};
