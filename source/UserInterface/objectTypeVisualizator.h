#pragma once

#include <map>
#include "objects\ObjectTypes.h"
#include "map\structure.h"

class CMapPointVisuzlizator
{
public:
   CMapPointVisuzlizator();
   char getObjectTypeChar( game_engine::ObjectType objType ) const;
   char getStructureTypeChar( game_engine::StructureType structureType ) const;

private:
   std::map< game_engine::ObjectType, char > objectTypeList;
   std::map< game_engine::StructureType, char > structureTypeList;

   void fillTypeObjectList();
   void fillStructureTypeList();
};
