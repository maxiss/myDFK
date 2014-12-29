#include "creature.h"

using namespace creatures;
using namespace gamemap;

gamemap::TObjectType CCreature::getObjectType() const
{
   return OBJ_TYPE_CREATURE;
}
