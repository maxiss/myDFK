#include "objectTypeVisualizator.h"

using namespace visualization;
using namespace gamemap;

struct TObjTypeChar
{
   const TObjectType objType;
   const char* ch;
};

struct TStructureTypeChar
{
   const TStructureType structureType;
   const char* ch;
};

CMapPointVisuzlizator::CMapPointVisuzlizator()
{
   fillTypeObjectList();
   fillStructureTypeList();
}

void CMapPointVisuzlizator::fillTypeObjectList()
{
   // TODO bear out to ini-file
   TObjTypeChar listChars[] = {
      { OBJ_TYPE_ITEM,     "i" }
    , { OBJ_TYPE_BUILDING, "b" }
    , { OBJ_TYPE_CREATURE, "@" }
      };

   size_t arrLen = sizeof( listChars ) / sizeof( *listChars );
   for ( size_t i = 0; i < arrLen; ++i )
   {
      objectTypeList.insert( std::make_pair <TObjectType, const char*> (listChars[i].objType, listChars[i].ch) );
   }
}

void CMapPointVisuzlizator::fillStructureTypeList()
{
   // TODO bear out to ini-file
   TStructureTypeChar listChars[] = {
      { STRUCTURE_NONE,    " " }
    , { STRUCTURE_FLOOR,   "." }
    , { STRUCTURE_WALL,    "#" }
      };

   size_t arrLen = sizeof( listChars ) / sizeof( *listChars );
   for ( size_t i = 0; i < arrLen; ++i )
   {
      structureTypeList.insert( std::make_pair <TStructureType, const char*> (listChars[i].structureType, listChars[i].ch) );
   }
}

const char* CMapPointVisuzlizator::getObjectTypeChar( const TObjectType& objType ) const
{
   const char* retVal = "";
   TObjectTypeList::const_iterator it = objectTypeList.find( objType );
   if ( it != objectTypeList.end() )
      retVal = it->second;
   return retVal;
}

const char* CMapPointVisuzlizator::getStructureTypeChar( const TStructureType& structureType ) const
{
   const char* retVal = "";
   TStructureTypeList::const_iterator it = structureTypeList.find( structureType );
   if ( it != structureTypeList.end() )
      retVal = it->second;
   return retVal;
}
