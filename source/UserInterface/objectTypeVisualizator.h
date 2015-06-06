#pragma once

#include <map>
#include "objects\ObjectTypes.h"
#include "map\structure.h"

class CMapPointVisuazlizator
{
public:
   static char getObjectTypeChar( game_engine::ObjectType objType );
   static char getStructureTypeChar( game_engine::StructureType structureType );
};
