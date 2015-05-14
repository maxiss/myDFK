#include "building.h"

using namespace buildings;

objects::TObjectType IBuilding::getObjectType() const
{
   return objects::TObjectType::building;
}
