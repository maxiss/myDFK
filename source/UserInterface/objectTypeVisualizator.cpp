#include "objectTypeVisualizator.h"

using namespace game_engine;

typedef std::map< game_engine::ObjectType, char > ObjectTypeMap;
typedef std::map< game_engine::StructureType, char > StructureTypeMap;

static ObjectTypeMap getObjectTypeList()
{
   // TODO move out to ini-file
   return {
            { ObjectType::Item,     'i' },
            { ObjectType::Building, 'b' },
            { ObjectType::Creature, '@' },
          };
}

static StructureTypeMap getStructureTypeList()
{
   // TODO move out to ini-file
   return {
            { StructureType::None,  ' ' },
            { StructureType::Floor, '.' },
            { StructureType::Wall,  '#' },
          };
}

char CMapPointVisuazlizator::getObjectTypeChar( ObjectType objType )
{
   static const ObjectTypeMap objectTypeList = getObjectTypeList();
   return objectTypeList.at( objType );
}

char CMapPointVisuazlizator::getStructureTypeChar( StructureType structureType )
{
   static const StructureTypeMap structureTypeList = getStructureTypeList();
   return structureTypeList.at( structureType );
}
