#include "objectContainer.h"

using namespace gamemap;

bool CObjectContainer::isEmpty() const
{
   return CBaseObjectContainer::isEmpty();
}

CObject* CObjectContainer::get()
{
   return getObject();
}

CObject* CObjectContainer::get() const
{
   return getObject();
}

CObject* CObjectContainer::get( const TObjectType& objType )
{
   return getObject( objType );
}

void CObjectContainer::add( CObject* object )
{
   addObject( object );
}

void CObjectContainer::remove( CObject* object )
{
   removeObject( object );
}
