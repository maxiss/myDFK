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
   objectTypeList.insert( std::make_pair( TObjectType::item,     'i' ) );
   objectTypeList.insert( std::make_pair( TObjectType::building, 'b' ) );
   objectTypeList.insert( std::make_pair( TObjectType::creature, '@' ) );
}

void CMapPointVisuzlizator::fillStructureTypeList()
{
   // TODO bear out to ini-file
   structureTypeList.insert( std::make_pair( TStructureType::none,  ' ' ) );
   structureTypeList.insert( std::make_pair( TStructureType::floor, '.' ) );
   structureTypeList.insert( std::make_pair( TStructureType::wall,  '#' ) );
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
