#include "baseObjectContainer.h"

using namespace gamemap;

bool CBaseObjectContainer::isEmpty() const
{
   return content.empty();
}

CObject* CBaseObjectContainer::getObject()
{
   CObject* retVal = nullptr;
   TObjectList::iterator it = content.begin();
   if ( it != content.end() )
      retVal = *it;

   return retVal;
}

CObject* CBaseObjectContainer::getObject() const
{
   CObject* retVal = nullptr;
   TObjectList::const_iterator it = content.begin();
   if ( it != content.end() )
      retVal = *it;

   return retVal;
}

CObject* CBaseObjectContainer::getObject( const TObjectType& objType )
{
   CObject* retVal = nullptr;

   TObjectList::iterator it = content.begin();
   while ( it != content.end() )
   {
      if ( (*it)->getObjectType() == objType )
      {
         retVal = *it;
         break;
      }

      ++it;
   }

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

