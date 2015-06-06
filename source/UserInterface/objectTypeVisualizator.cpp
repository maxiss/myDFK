#include "objectTypeVisualizator.h"

using namespace game_engine;

CMapPointVisuzlizator::CMapPointVisuzlizator()
{
   fillTypeObjectList();
   fillStructureTypeList();
}

void CMapPointVisuzlizator::fillTypeObjectList()
{
   // TODO bear out to ini-file
   objectTypeList.insert( std::make_pair( ObjectType::Item,     'i' ) );
   objectTypeList.insert( std::make_pair( ObjectType::Building, 'b' ) );
   objectTypeList.insert( std::make_pair( ObjectType::Creature, '@' ) );
}

void CMapPointVisuzlizator::fillStructureTypeList()
{
   // TODO bear out to ini-file
   structureTypeList.insert( std::make_pair( StructureType::None,  ' ' ) );
   structureTypeList.insert( std::make_pair( StructureType::Floor, '.' ) );
   structureTypeList.insert( std::make_pair( StructureType::Wall,  '#' ) );
}

char CMapPointVisuzlizator::getObjectTypeChar( ObjectType objType ) const
{
   char retVal = '\0';
   auto it = objectTypeList.find( objType );
   if ( it != objectTypeList.end() )
      retVal = it->second;
   return retVal;
}

char CMapPointVisuzlizator::getStructureTypeChar( StructureType structureType ) const
{
   char retVal = '\0';
   auto it = structureTypeList.find( structureType );
   if ( it != structureTypeList.end() )
      retVal = it->second;
   return retVal;
}
