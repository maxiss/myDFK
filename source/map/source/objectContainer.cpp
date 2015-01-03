#include "objectContainer.h"

using namespace gamemap;

bool CObjectContainer::isEmpty() const
{
   return content.empty();
}

CObject* CObjectContainer::get()
{
   CObject* retVal = nullptr;
   TObjectList::iterator it = content.begin();
   if ( it != content.end() )
      retVal = *it;

   return retVal;
}

CObject* CObjectContainer::get() const
{
   CObject* retVal = nullptr;
   TObjectList::const_iterator it = content.begin();
   if ( it != content.end() )
      retVal = *it;

   return retVal;
}

CObject* CObjectContainer::get( const TObjectType& objType )
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

void CObjectContainer::add( CObject* object )
{
   content.push_back( object );
}

void CObjectContainer::remove( CObject* object )
{
   content.remove( object );
}
