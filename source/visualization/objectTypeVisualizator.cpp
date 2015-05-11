#include "objectTypeVisualizator.h"

using namespace visualization;
using namespace gamemap;

CMapPointVisuzlizator::CMapPointVisuzlizator()
{
   fillTypeObjectList();
   fillStructureTypeList();
}

void CMapPointVisuzlizator::fillTypeObjectList()
{
   // TODO bear out to ini-file
   objectTypeList.insert( std::make_pair( OBJ_TYPE_ITEM,     'i' ) );
   objectTypeList.insert( std::make_pair( OBJ_TYPE_BUILDING, 'b' ) );
   objectTypeList.insert( std::make_pair( OBJ_TYPE_CREATURE, '@' ) );
}

void CMapPointVisuzlizator::fillStructureTypeList()
{
   // TODO bear out to ini-file
   structureTypeList.insert( std::make_pair( STRUCTURE_NONE,    ' ' ) );
   structureTypeList.insert( std::make_pair( STRUCTURE_FLOOR,   '.' ) );
   structureTypeList.insert( std::make_pair( STRUCTURE_WALL,    '#' ) );
}

char CMapPointVisuzlizator::getObjectTypeChar( const TObjectType& objType ) const
{
   char retVal = '\0';
   auto it = objectTypeList.find( objType );
   if ( it != objectTypeList.end() )
      retVal = it->second;
   return retVal;
}

char CMapPointVisuzlizator::getStructureTypeChar( const TStructureType& structureType ) const
{
   char retVal = '\0';
   auto it = structureTypeList.find( structureType );
   if ( it != structureTypeList.end() )
      retVal = it->second;
   return retVal;
}
