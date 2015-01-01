#include "baseObjectContainer.h"

using namespace gamemap;

CObject* CBaseObjectContainer::getObject()
{
   CObject* retVal = nullptr;
   TObjectList::iterator it = content.begin();
   if ( it != content.end() )
      retVal = *it;

   return retVal;
}

void CBaseObjectContainer::addObject( CObject* object )
{
   content.push_back( object );
}

void CBaseObjectContainer::removeObject( CObject* object )
{
   content.remove( object );
}

