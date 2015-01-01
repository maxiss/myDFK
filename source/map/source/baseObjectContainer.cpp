#include "baseObjectContainer.h"

using namespace gamemap;

void CBaseObjectContainer::addObject( CObject* object )
{
   content.push_back( object );
}

void CBaseObjectContainer::removeObject( CObject* object )
{
   content.remove( object );
}

