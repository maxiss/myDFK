#include "objectContainer.h"

using namespace gamemap;

void CObjectContainer::add( CObject* object )
{
   addObject( object );
}

void CObjectContainer::remove( CObject* object )
{
   removeObject( object );
}
