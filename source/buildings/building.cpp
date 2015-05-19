#include "building.h"

using namespace buildings;
using namespace objects;

TObjectType IBuilding::getObjectType() const
{
   return TObjectType::building;
}
