#include "objectTypeVisualizator.h"

using namespace visualization;
using namespace gamemap;

struct TObjTypeChar
{
   const TObjectType objType;
   const char* ch;
};

CTypeObjectVisualizator::CTypeObjectVisualizator()
{
   // TODO bear out to ini-file
   TObjTypeChar listChars[] = {
      { OBJ_TYPE_EMPTY,    "." }
    , { OBJ_TYPE_ITEM,     "i" }
    , { OBJ_TYPE_BUILDING, "b" }
    , { OBJ_TYPE_CREATURE, "@" }
      };

   size_t arrLen = sizeof( listChars ) / sizeof( *listChars );
   for ( size_t i = 0; i < arrLen; ++i )
   {
      typeObjectList.insert( std::make_pair <TObjectType, const char*> (listChars[i].objType, listChars[i].ch) );
   }
}

const char* CTypeObjectVisualizator::getTypeObjectChar( const TObjectType& objType ) const
{
   const char* retVal = "";
   TTypeObjectList::const_iterator it = typeObjectList.find( objType );
   if ( it != typeObjectList.end() )
      retVal = it->second;
   return retVal;
}
