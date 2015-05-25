#pragma once

#include <memory>
#include <list>
#include "game/game_export.h"
#include "mapData.h"

namespace gamemap
{
	struct TMapPoint
	{
	   TCoords coords;
	   TStructureType structureType;
	   objects::TConstObjectList objectList;
	};
	
	typedef std::list< TMapPoint > TMapPointList;
	
	class GAME_EXPORT IMap
	{
	public:
	   typedef std::shared_ptr< const IMap > ConstPtr;
      virtual TMapPointList getMapPositionList() const = 0;
      virtual TMapPointList getMapChanges() const = 0;
	};
}
